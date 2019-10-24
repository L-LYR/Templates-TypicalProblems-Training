#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 80
int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    const double log_10_2 = log10(2);
    int M, E;
    double tab[10][30];
    for (M = 0; M <= 9; ++M)
        for (E = 1; E <= 30; ++E)
            tab[M][E - 1] = log10(1.0 - pow(0.5, M + 1)) + (pow(2, E) - 1) * log_10_2;

    double A, temp;
    long long B;
    char buffer[BUFFER_SIZE], *e;
    int flag;
    while (scanf("%s", buffer) && *buffer != '0' && *(buffer + 1) != 'e')
    {
        flag = 0;
        e = strchr(buffer, 'e');
        *e = '\0';
        sscanf(buffer, "%lf", &A);
        sscanf(e + 1, "%lld", &B);
        temp = log10(A) + B;
        for (M = 0; M <= 9; ++M)
        {
            for (E = 1; E <= 30; ++E)
                if (fabs(temp - tab[M][E - 1]) < 1e-4)
                {
                    printf("%d %d\n", M, E);
                    flag = 1;
                    break;
                }
            if (flag)
                break;
        }
    }
    // fclose(b);
    return 0;
}