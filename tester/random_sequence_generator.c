#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numbers[100];
    int i, j, temp;

    // Initialize the numbers array from 1 to 100
    for (i = 0; i < 100; i++) {
        numbers[i] = i + 1;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Shuffle the numbers array using Fisher-Yates algorithm
    for (i = 99; i > 0; i--) {
        j = rand() % (i + 1);
        // Swap numbers[i] and numbers[j]
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Print the shuffled array
    for (i = 0; i < 100; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}