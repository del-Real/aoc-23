// =========================
// AOC 2023 / Day 1 / Part 2
// =========================

// 1. Read input file [X]
// 2. Store digits of each line into an array
// 3. Check array length
// 4. Concatenate digits depending of array length
// 5. Sum all

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int concatenate(int x, int y);

int main() {
    int ch, sum;
    int i;
    int digits[10];

    FILE *fp;

    fp = fopen("day1_input.txt", "r");  // "r" read mode

    if (fp == NULL)  // check input file
    {
        perror("Error: Input File not found");
        return 1;
    }

    // Print file
    while ((ch = fgetc(fp)) != EOF) {
        // digit found
        if (isdigit(ch)) {
            digits[i] = ch - '0';     // convert to integer
            printf("%d", digits[i]);  // print digits
            i++;
        }

        // contains
        if (strstr(digits, "one") != NULL) {
            printf("HOLAOERFKSDOPKGOPDKOPSFGOPK");
        }

        // jump line found
        if (ch == '\n') {
            int number;

            printf("---%d---", i);  // print n of digits

            // check array length
            switch (i) {
                case 1:
                    // concatenate digit twice
                    number = concatenate(digits[0], digits[0]);
                    printf("%d", number);
                    sum += number;
                    break;

                case 2:
                    // concatenate both digits
                    number = concatenate(digits[0], digits[1]);
                    printf("%d", number);
                    sum += number;
                    break;
                default:
                    if (i >= 3) {
                        // concatenate first and last digit
                        number = concatenate(digits[0], digits[i - 1]);
                        printf("%d", number);
                        sum += number;
                    }
                    break;
            }

            // reset i and array for the next line
            i = 0;
            int digits[10];
            printf("\n");
        }
    }
    printf("Result: %d\n", sum);
    fclose(fp);

    return 0;
}

int concatenate(int x, int y) {
    int pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}