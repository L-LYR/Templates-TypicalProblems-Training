#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(void)
{
    char a[100];
    while (cin.getline(a, 100))
    {
        int i = 0;
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] = a[i] - 32;
        for (i = 1; a[i] != '\0'; i++)
        {
            if (a[i] == ' ' || a[i] == '\t' || a[i] == '\r')
            {
                if (a[i + 1] >= 'a' && a[i + 1] <= 'z')
                    a[i + 1] = a[i + 1] - 32;
            }
        }
        printf("%s\n", a);
    }
    return 0;
}
