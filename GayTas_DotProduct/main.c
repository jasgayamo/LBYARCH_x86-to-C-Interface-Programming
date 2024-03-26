//Marc Lowell Anthony O. Tasarra, Jasmine B. Gayamo

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

clock_t start, end;

void randomizer(float vectorA[], float vectorB[]) {
    int i;
    srand((unsigned int)time(NULL));

    // Fill vectorA and vectorB with random float numbers
    for (i = 0; i < 30; i++) {
        vectorA[i] = (float)rand() / 1000; // Generates a random float between 0 and 1
        vectorB[i] = (float)rand() / 1000;
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
    float vectorA[30];
    float vectorB[30];
    float sdot = 0;
    //create the values
    randomizer(vectorA, vectorB);

    //Compute dot product set at n=20
    int n = 20;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=20
    n = 24;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    //Compute dot product set at n=20
    n = 30;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("n = %d: ", n);
    printf("%.2f\n", sdot);
    tellTime(time);

    return 0;

}