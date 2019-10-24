#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 30

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *ans[] = {"is not a palindrome.", "is a regular palindrome.", "is a mirrored string.", "is a mirrored palindrome."};

char reverse(char input)
{
    if (isalpha(input))
        return rev[input - 'A'];
    else
        return rev[input - '0' + 25];
}

int main(void)
{

    // FILE *b = freopen("output.txt", "w", stdout);
    char input[N];
    while (scanf("%s", input) == 1)
    {
        char *head = input, *tail = input + strlen(input) - 1;
        int flag_1 = 1, flag_2 = 1;
        while (tail - head >= 0) //here equal-to
        {
            if (*head != *tail)
                flag_1 = 0;
            if (reverse(*head) != *tail)
                flag_2 = 0;
            if (flag_1 == 0 && flag_2 == 0)
                break;
            tail--;
            head++;
        }
        printf("%s -- %s\n\n", input, ans[2 * flag_2 + flag_1]);
        memset(input, ' ', sizeof(input));
    }

    // fclose(b);
    return 0;
}
