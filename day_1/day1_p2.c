// =========================
// AOC 2023 / Day 1 / Part 2
// =========================

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int concatenate(int x, int y);

int main() {
    int ch, sum;
    int i, j, k;
    sum = i = j = k = 0;
    int num;

    int h = 0;

    const char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char line[20];
    int digits[10];

    FILE *fp;

    fp = fopen("day1_input.txt", "r");

    if (fp == NULL) {
        perror("Error: Input File not found");
        return 1;
    }

    // Main loop
    while ((ch = fgetc(fp)) != EOF) {
        printf("%d - ", h + 1);
        h++;

        // Reset line and digits arrays
        memset(line, 0, sizeof(line));
        memset(digits, 0, sizeof(digits));
        i = j = 0;

        // line iteration
        while (ch != '\n' && ch != EOF) {
            line[i] = ch;
            i++;

            // check if constains number in letter
            for (k = 0; k < 9; k++) {
                if (strstr(line, numbers[k])) {
                    digits[j] = k + 1;
                    j++;

                    // Reset line array
                    i = 0;
                    memset(line, 0, sizeof(line));
                }
            }

            // check if ch is digit
            if (isdigit(ch)) {
                digits[j] = ch - '0';
                j++;
            }
            ch = fgetc(fp);
        }

        // print results
        for (k = 0; k < j; k++) {
            printf("%d", digits[k]);
        }

        printf(" \t\t%d\t ", j);

        // check array length
        switch (j) {
        case 1:
            // concatenate digit twice
            num = concatenate(digits[0], digits[0]);
            printf("%d", num);
            sum += num;
            break;

        case 2:
            // concatenate both digits
            num = concatenate(digits[0], digits[1]);
            printf("%d", num);
            sum += num;
            break;
        default:
            if (j >= 3) {
                // concatenate first and last digit
                num = concatenate(digits[0], digits[j - 1]);
                printf("%d", num);
                sum += num;
            }
            break;
        }

        printf("\n");
        j = 0;
    }

    fclose(fp);
    printf("\nTOTAL SUM: %d\n", sum);
    return 0;
}

int concatenate(int x, int y) {
    int pow = 10;
    while (y >= pow)
        pow *= 10;
    return x * pow + y;
}