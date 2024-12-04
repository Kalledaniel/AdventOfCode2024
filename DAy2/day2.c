#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


# define MAX_ROWS 1000
# define MAX_COLUMNS 10
# define BUFFER_SIZE 1024


int main() {
    printf("Start of Day 2\n");
    // Stary 
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int *rows[MAX_ROWS];
    int rowSizes[MAX_ROWS];
    int rowCount = 0;

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), file)) {
        int *row = (int *) malloc(MAX_COLUMNS * sizeof(int));
        int value, colCount = 0;
        char *token = strtok(buffer, " \n");

        // Parse the numbers in the line
        while (token != NULL) {
            value = atoi(token);
            row[colCount++] = value; // Store the number in the row
            token = strtok(NULL, " \n");
        }

        rows[rowCount] = row;       // Store the row in the array
        rowSizes[rowCount] = colCount; // Store the number of columns in this row
        rowCount++;

        if (rowCount >= MAX_ROWS) {
            printf("Error: Exceeded maximum number of rows (%d).\n", MAX_ROWS);
            break;
        }
    }

    fclose(file);

    // Print the rows to verify
    int number_of_safe_rows = 0;
    for (int i = 0; i < rowCount; i++) {
        int current_number = rows[i][0];
        bool is_increase;
        bool success = true;
        if (current_number < rows[i][1]) {
            is_increase = true;
        } else {
            is_increase = false;
        }
        for (int j = 1; j < rowSizes[i]; j++) { 
            int diffrence = rows[i][j] - current_number;
            if (is_increase) {
                if (1 <= diffrence && diffrence <= 3) {
                    is_increase = true;
                } else {
                    is_increase = false;
                    success = false;
                    break;
                }
            } else {
                if (-3 <= diffrence && diffrence <= -1) {   
                    is_increase = false;
                } else {
                    is_increase = true;
                    success = false;
                    break;
                }
            }
            current_number = rows[i][j];
        }

        if (success) {
            number_of_safe_rows++;
        }
    }

    printf("Number of safe rows: %d\n", number_of_safe_rows);


    // part 2

    int safe_flors = 0;
    for (int i = 0; i < rowCount; i++) {
        
        for (int j = 0; j < rowSizes[i]; j++) {
            int current_number = rows[i][0];
            bool is_increase;
            bool success = true;
            if (current_number < rows[i][1]) {
                is_increase = true;
            } else {
                is_increase = false;
            }
            if (j == 0) {
                current_number = rows[i][1];
                if (current_number < rows[i][2]) {
                    is_increase = true;
                } else {
                    is_increase = false;
                }
            }
            if (j == 1) {
                if (current_number < rows[i][2]) {
                    is_increase = true;
                } else {
                    is_increase = false;
                }
            }

            int k_place = 1;
            if (j == 0) {
                k_place = 2;
            }

            for (int k = k_place; k < rowSizes[i]; k++) {
                if (j == k) {
                    continue;
                }
                int diffrence = rows[i][k] - current_number;
                if (is_increase) {
                    if (1 <= diffrence && diffrence <= 3) {
                        is_increase = true;
                    } else {
                        is_increase = false;
                        success = false;
                        break;
                    }
                } else {
                    if (-3 <= diffrence && diffrence <= -1) {   
                        is_increase = false;
                    } else {
                        is_increase = true;
                        success = false;
                        break;
                    }
                }
                current_number = rows[i][k];
            }

            if (success) {
                safe_flors++;
                break;
            }
        }
    }

    printf("Number of safe floors: %d\n", safe_flors);

    
    // Free allocated memory
    for (int i = 0; i < rowCount; i++) {
        free(rows[i]);
    }

    return 0;
}