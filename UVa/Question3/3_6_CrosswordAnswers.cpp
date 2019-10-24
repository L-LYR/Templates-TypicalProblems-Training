#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SCALE 20

char puzzle[MAX_SCALE][MAX_SCALE];
short square[MAX_SCALE][MAX_SCALE];

int main(void)
{
    // FILE *a = freopen("input_3_6.txt", "r", stdin);
    // FILE *b = freopen("output_3_6.txt", "w", stdout);
    int r, c, number, counter = 1;
    int i, j, k;
    while (scanf("%u", &r) == 1 && r != 0)
    {
        scanf("%u", &c);
        getchar(); //skip the \n
        number = 1;
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                scanf("%c", &puzzle[i][j]);
                if (puzzle[i][j] == '*')
                    square[i][j] = -1;
                else if (i - 1 < 0 || square[i - 1][j] == -1 || j - 1 < 0 || square[i][j - 1] == -1) //pay attention to the order
                {
                    square[i][j] = number;
                    ++number;
                }
            }
            getchar(); //skip the \n
        }
        // for (int i = 0; i < r; ++i)
        // {
        //     for (int j = 0; j < c; ++j)
        //         printf("%-4hd ", square[i][j]);
        //     printf("\n");
        // }
        if (counter != 1)
            printf("\n");
        printf("puzzle #%d:\nAcross\n", counter++);
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                if (square[i][j] > 0 && ((j - 1) < 0 || square[i][j - 1] == -1))
                {
                    printf("%3d.", square[i][j]);
                    for (k = j; square[i][k] != -1 && k < c; ++k)
                        printf("%c", puzzle[i][k]);
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for (i = 0; i < r; ++i)
        {
            for (j = 0; j < c; ++j)
            {
                if (square[i][j] > 0 && ((i - 1) < 0 || square[i - 1][j] == -1))
                {
                    printf("%3d.", square[i][j]);
                    for (k = i; square[k][j] != -1 && k < r; ++k)
                        printf("%c", puzzle[k][j]);
                    printf("\n");
                }
            }
        }
        memset(puzzle, 0, sizeof(puzzle));
        memset(square, 0, sizeof(square));
    } //while
    // fclose(a);
    // fclose(b);
    return 0;
}