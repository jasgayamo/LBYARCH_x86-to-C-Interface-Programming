//Marc Lowell Anthony O. Tasarra, Jasmine B. Gayamo

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 1073741824 // 2^30

extern float dotProduct_asm(int n, float A[], float B[]);


clock_t start, end;

void popuArr(float vectorA[], float vectorB[]) {
  
    // Fill vectorA and vectorB with numbers from 0 to 29
    for (int i = 0; i < ARRAY_SIZE; i++) {
        vectorA[i] = (float)(i); 
        vectorB[i] = (float)(i);
    }

}

float dotProduct(int n, float sdot, float A[], float B[]) {
    //start time
    start = clock();

    //temporarily hold the product each iteration
    float holder = 0;
    for (int x = 0; x < n; x++) {
        holder = A[x] * B[x];
        sdot = sdot + holder;
    }

    //end time
    end = clock();
    //return the answer for the computation
    return sdot;
}

void tellTime(double time) {
    //calculate the time taken
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    //print the time taken
    printf("Time Taken By the Kernel: %f seconds\n", time);
}


int main(int argc, char* argv[]) {
    double time = 0;
    float* vectorA = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float* vectorB = (float*)malloc(ARRAY_SIZE * sizeof(float));
    float sdot = 0;
    int n = 0;
    //create the values
    popuArr(vectorA, vectorB);

    //Compute dot product set at n=20
    n = pow(2,20);
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=20
    n = pow(2,24);
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=20
    n = pow(2,30);
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    
    return 0;

}