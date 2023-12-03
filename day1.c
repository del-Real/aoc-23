// =====================
// AOC 2023 - Day 1
// =====================

// 1. Read an input file [X]
// 2. Read file line by line [X]
// 3. Check char if is digit
// 4. Store first digit found in line
// 5. Check if there are more digits in line
// 6. If there are more digits -> Always choose last digit
// 7. If not -> duplicate existing digit
// 8. Combine two digits forming a two-digit number
// 9. Jump next line and repeat
// 10. Sum all

#include <stdio.h>
#include <ctype.h>

int main()
{

    FILE *fp;
    int ch, number, sum;

    fp = fopen("day1_input.txt", "r"); // read mode

    if (fp == NULL) // check input file
    {
        perror("Error opening input file");
        return 1;
    }

    // Print file
    while ((ch = fgetc(fp)) != EOF)
    {
        // printf("%c", ch);

        while ((ch = fgetc(fp)) != '\n') // check line by line
        {

            if (isdigit(ch))
            {
                printf(" _ ");
            }
            else
            {
                printf("%c", ch);
            }
        }
    }

    fclose(fp);

    return 0;
}
