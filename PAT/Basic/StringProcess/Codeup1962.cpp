#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char temp[1005];
int main(void)
{
    while (cin.getline(temp, 1000))
    {
        char s[1005][1005], a[1005], b[1005], ch;
        int op = 0, oq = 0, i;
        for (i = 0; i <= strlen(temp); ++i)
        {
            if (temp[i] == ' ' || i == strlen(temp))
                s[op][oq] = '\0', oq = 0, op++;
            else
                s[op][oq++] = temp[i];
        }
        cin.getline(a, 1000);
        cin.getline(b, 1000);
        for (i = 0; i < op; i++)
            if (strcmp(s[i], a) == 0)
                strcpy(s[i], b);
        for (i = 0; i < op; i++)
            i ? printf(" %s", s[i]) : printf("%s", s[i]);
        putchar('\n');
    }
    return 0;
}