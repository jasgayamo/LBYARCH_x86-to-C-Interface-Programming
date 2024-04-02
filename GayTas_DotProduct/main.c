//S14 Marc Lowell Anthony O. Tasarra, Jasmine B. Gayamo

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 1073741824 // 2^30

extern float dotProduct86(float A[], float B[], int n);

clock_t start, end;

void popuArr(float vectorA[], float vectorB[]) {
    srand((unsigned int)time(NULL));

    // Fill vectorA and vectorB with numbers from a random float between 1 and 10
    for (int i = 0; i < ARRAY_SIZE; i++) {
        vectorA[i] = ((float)rand() / RAND_MAX) * 9 + 1; // Generates a random float between 1 and 10
        vectorB[i] = ((float)rand() / RAND_MAX) * 9 + 1;
    }
}



float dotProduct(int n, float A[], float B[]) {
    //start time
    start = clock();

    //temporarily hold the product each iteration
    float holder0 = 0;
    float holder1 = 0;
    for (int x = 0; x < n; x++) {
        holder0 = A[x] * B[x];
        holder1 = holder1 + holder0;
    }

    //end time
    end = clock();
    //return the answer for the computation
    return holder1;
}

static void tellTime(double time) {
    //calculate the time taken
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    //print the time taken
    printf("Time Taken By the Kernel: %f seconds\n", time);
}

static void printCdisplay() {
    printf("\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("Dot Product Using C Kernel\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("\n");
}

static void print86display() {
    printf("\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("Dot Product Using x86_64 Assembly Kernel\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("\n");
}

void printCMP(int n, float holderSDOT, float sdot) {
    if (holderSDOT == sdot) {
        printf("\nFor n = %d:\n", n);
        printf("Both Outputs of C and x86_64 Kernels are the Same\n");
    }
    else {
        printf("\nFor n = %d:\n", n);
        printf("Both Outputs of C and x86_64 Kernels are not the Same\n");
    }
}

static void printDOTP() {
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    printf("CALCULATING DOT PRODUCT FOR TWO VECTORS\n");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
}

static void pressToExit() {
    //Wait for a key press before closing the application
    printf("\nPress any key to close the application...");
    getchar();
}

int main(int argc, char* argv[]) {
    double time = 0;
    float* vectorA = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* vectorB = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float sdot = 0;
    int n = 0;
    float holderSDOT = 0;

    printDOTP();

    //create the values
    popuArr(vectorA, vectorB);

    printCdisplay();
    //Compute dot product set at n=2^20 using C kernel
    n = pow(2,20);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);
    holderSDOT = sdot;

    print86display();
    //Compute dot product set at n=2^20 using x86_64 Assembly kernel
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compare the values of holderSDOT(value of C kernel) and sdot(value of x86_64) where n = 2^20
    printCMP(n, holderSDOT, sdot);

    printCdisplay();
    //Compute dot product set at n=2^24 using C kernel
    n = pow(2,24);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);
    holderSDOT = sdot;

    print86display();
    //Compute dot product set at n=2^24 using x86_64 Assembly kernel
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compare the values of holderSDOT(value of C kernel) and sdot(value of x86_64) where n = 2^24
    printCMP(n, holderSDOT, sdot);

    printCdisplay();
    //Compute dot product set at n=2^30 using C kernel
    n = pow(2,30);
    sdot = dotProduct(n, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);
    holderSDOT = sdot;

    print86display();
    //Compute dot product set at n=2^30 using x86_64 Assembly kernel
    start = clock();
    sdot = dotProduct86(vectorA, vectorB, n);
    end = clock();
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);
    
    //Compare the values of holderSDOT(value of C kernel) and sdot(value of x86_64) where n = 2^30
    printCMP(n, holderSDOT, sdot);

    //Close the application with a button press
    pressToExit();

    //free the memory allocated to the arrray (vectors) A and B
    free(vectorA);
    free(vectorB);



    return 0;

}
