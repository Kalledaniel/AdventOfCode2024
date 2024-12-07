#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void extractAndMultiply(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int total_multiplications = 0;
    int count = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *ptr = buffer;
        while ((ptr = strstr(ptr, "mul(")) != NULL) {
            int num1, num2;
            char end_char;

           if (sscanf(ptr, "mul(%d,%d%c", &num1, &num2, &end_char) == 3 && end_char == ')') {
                printf("(%d)Found: mul(%d, %d) -> Product: %d\n", count, num1, num2, num1 * num2);
                total_multiplications+= num1 * num2;
                count++;
            }
            ptr += 4; // Move past "mul("
        }
    }
    printf("Total multiplications: %d\n", total_multiplications);
     // part 1 175700056? i get 8211015
     // 174045474
     // 175700056
        // part 2 71668682? i get null
    fclose(file);
}

int main() {
    const char *filename = "test_input.txt"; 
    extractAndMultiply(filename);
    return 0;
}