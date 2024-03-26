section .text
global dotProduct86

dotProduct86:
    ; Parameters are passed in registers: rcx, rdx, r8, r9
    ; rcx contains the size of the arrays (n)
    ; rdx contains the initial value of the dot product (sdot)
    ; r8 contains the address of array A
    ; r9 contains the address of array B

    ; Check for valid pointers
    test r8, r8  ; Test if pointer to A is null
    jz endDotProduct  ; If null, exit function
    test r9, r9  ; Test if pointer to B is null
    jz endDotProduct  ; If null, exit function

    ; Check if size of arrays is non-negative
    cmp rcx, 0
    jle endDotProduct  ; If size <= 0, exit function

    ; Initialize xmm3 to sdot
    movss xmm3, dword [rdx]

    ; Loop through the arrays
    xor r10, r10  ; Counter for loop
dotProductLoop:
    cmp r10, rcx  ; Check if counter reached n
    jge endDotProduct  ; If greater or equal, exit loop
    ; Load elements from arrays A and B
    movss xmm0, dword [r8 + r10 * 4]  ; Load A[x] into xmm0
    movss xmm1, dword [r9 + r10 * 4]  ; Load B[x] into xmm1
    ; Multiply elements and accumulate the result
    mulss xmm1, xmm0  ; Multiply A[x] with B[x]
    addss xmm3, xmm1  ; Accumulate the result
    inc r10  ; Increment loop counter
    jmp dotProductLoop  ; Repeat the loop

endDotProduct:
    ; Store the result back to sdot
    movss dword [rdx], xmm3

    ret
