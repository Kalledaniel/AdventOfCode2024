#include <stdio.h>
#include <stdlib.h>


int compareAscending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *file;
    int array1[1000];
    int array2[1000];
    int index = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read numbers from the file and store in arrays
    while (fscanf_s(file, "%d %d", &array1[index], &array2[index]) == 2) {
        index++;
        if (index >= 1001) {
            printf("Error: Exceeded maximum allowed lines (%d).\n", 1001);
            break;
        }
    }

    fclose(file);    
    qsort(array1, index, sizeof(int), compareAscending);
    qsort(array2, index, sizeof(int), compareAscending);

    int totaldiff = 0;
    for (int i = 0; i < index; i++) {
        // printf("%d ", array1[i]);
        totaldiff += abs(array1[i] - array2[i]);
    }

    printf("part 1: Total difference: %d\n", totaldiff);


    // Part 2

    int similarity_score = 0;
    for (int i = 0; i < index; i++) {
        int similarity_numbers = 0;
        for (int j = 0; j < index; j++) {
            if (array1[i] == array2[j]) {
                similarity_numbers++;
            }
        }

        similarity_score += (array1[i] * similarity_numbers);
    }

    printf("part 2: Similarity score: %d\n", similarity_score);


    return 0;
}



