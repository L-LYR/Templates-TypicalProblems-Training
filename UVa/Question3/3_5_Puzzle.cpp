#include <stdio.h>
#include <string.h>
#include <stdbool.h>
const char *illegal = "This puzzle has no final configuration.";
struct blank
{
    int x;
    int y;
};
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int main(void)
{
    struct blank B;
    char blocks[5][5], ch;
    int counter = 1;
    bool move;

    while (true)
    {
        move = true;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                scanf("%c", &blocks[i][j]);
                if (blocks[0][0] == 'Z')
                    return 0;
                if (blocks[i][j] == ' ')
                {
                    B.x = i;
                    B.y = j;
                }
            }
            getchar();
        }
        while ((ch = getchar()) != '0')
        {
            if (ch == 'A' && B.x - 1 >= 0)
            {
                swap(&blocks[B.x - 1][B.y], &blocks[B.x][B.y]);
                --B.x;
            }
            else if (ch == 'B' && B.x + 1 <= 4)
            {
                swap(&blocks[B.x + 1][B.y], &blocks[B.x][B.y]);
                ++B.x;
            }
            else if (ch == 'L' && B.y - 1 >= 0)
            {
                swap(&blocks[B.x][B.y - 1], &blocks[B.x][B.y]);
                --B.y;
            }
            else if (ch == 'R' && B.y + 1 <= 4)
            {
                swap(&blocks[B.x][B.y + 1], &blocks[B.x][B.y]);
                ++B.y;
            }
            else if (ch != '\n')
            {
                while (ch != '0')
                    ch = getchar();
                move = false;
                break;
            }
        }
        getchar();
        if (counter != 1)
            printf("\n");
        printf("Puzzle #%d:\n", counter++);
        if (move)
        {
            for (int i = 0; i < 5; ++i)
            {
                printf("%c", blocks[i][0]);
                for (int j = 1; j < 5; ++j)
                    printf(" %c", blocks[i][j]);
                printf("\n");
            }
        }
        else
            printf("%s\n", illegal);
    }
}