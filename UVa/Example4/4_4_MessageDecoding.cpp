#include <stdio.h>
#include <string.h>

const int offset[] = {0, 1, 4, 11, 26, 57, 120};
const int end[] = {1, 3, 7, 15, 31, 63, 127};

typedef enum
{
    LINE_START,
    LINE_END,
    LITERAL,
    FILE_END
} status;

status get_literal(char *header, char *ansp, int width)
{
    char ch;
    int loc = 0, wid = width;
    while (wid > 0)
    {
        ch = getchar();
        if (ch == '\n' || ch == '\r')
            continue;
        if (ch == '1')
            loc += 1 << (wid - 1);
        wid--;
    }
    if (loc == end[width - 1])
        return LINE_END;
    else
    {
        *ansp = *(header + offset[width - 1] + loc);
        return LITERAL;
    }
}

#define BUFFER_SIZE 10000

int main(void)
{
    FILE *a = freopen("input.txt", "r", stdin);
    FILE *b = freopen("output.txt", "w", stdout);
    char header[BUFFER_SIZE], ans[BUFFER_SIZE];
    char ch, *p;
    int width, temp;
    status flag;
    while (scanf("%[^\n]", header) == 1)
    {
        flag = LINE_START;
        p = ans;
        while (1)
        {
            switch (flag)
            {
            case LINE_START:

                for (temp = 3, width = 0; temp > 0;)
                {
                    ch = getchar();
                    if (ch == '\n' || ch == '\r')
                        continue;
                    if (ch == '1')
                        width += 1 << (temp - 1);
                    // width = (width << 1) + ch - '0';
                    --temp;
                }

                if (width != 0)
                    flag = LITERAL;
                else
                    flag = FILE_END;

                break;
            case LITERAL:
                flag = get_literal(header, p, width);
                if (flag == LITERAL)
                    ++p;
                break;
            case LINE_END:
                flag = LINE_START;
                break;
            }
            if (flag == FILE_END)
            {
                *p = '\0';
                printf("%s\n", ans);
                break;
            }
        }
        getchar();
    }
    fclose(a);
    fclose(b);
    return 0;
}