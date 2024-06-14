// =========================
// AOC 2023 / Day 2 / Part 1
// =========================

// AVAILABLE: 12 red cubes, 13 green cubes, 14 blue cubes.

#include <ctype.h>
#include <stdio.h>

int main() {
    FILE *fp;
    int ch, sum;
    int i, j;
    i = j = 0;  // always initialize to avoid errors
    int games[100][2];

    fp = fopen("day2_input.txt", "r");  // "r" read mode

    if (fp == NULL)  // check input file
    {
        perror("input file Error");
        return 1;
    }

    printf("Game %d: ", i + 1);
    // Print file
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            printf("\n");
            printf("Game %d: ", i + 1);
            i++;
        }

        // digit found
        if (isdigit(ch)) {
            sum = ch - '0';
            printf("%d", sum);
        }
    }
    // printf("Result: %d\n", sum);
    fclose(fp);

    return 0;
}