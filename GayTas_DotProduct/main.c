//Marc Lowell Anthony O. Tasarra, Jasmine B. Gayamo

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void randomizer(float vectorA[], float vectorB[]){
    int i;
	srand((unsigned int)time(NULL));

    // Fill vectorA and vectorB with random float numbers
    for (i = 0; i < 30; i++) {
        vectorA[i] = (float)rand() /1000; // Generates a random float between 0 and 1
        vectorB[i] = (float)rand() /1000;
    }

}

float dotProduct(int n, float sdot, float A[], float B[]) {
    //temporarily hold the product each iteration
    float holder = 0;

    for (int x = 0; x < n; x++) {
        holder = A[x] * B[x];
        sdot = sdot + holder;
    }

    //return the answer for the computation
    return sdot;
}


int main(int argc, char* argv[]) {
    float vectorA[30];
    float vectorB[30];
    float sdot = 0;
    //create the values
    randomizer(vectorA, vectorB);

    //Compute dot product set at n=20
    int n = 20;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("%.2f\n", sdot);

    //Compute dot product set at n=20
    n = 24;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("%.2f\n", sdot);

    //Compute dot product set at n=20
    n = 30;
    sdot = dotProduct(n, sdot, vectorA, vectorB);
    printf("%.2f\n", sdot);

    return 0;

}
