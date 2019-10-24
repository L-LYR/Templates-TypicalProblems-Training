#include <iostream>

#define Bound 100000
int generator[Bound + 45];
int main(void)
{
    // FILE *f = freopen("output.txt", "w", stdout);
    for (int i = 1; i < Bound; ++i)
    {
        int temp = i, x = i;
        while (temp != 0)
        {
            x += temp % 10;
            temp /= 10;
        }
        if (generator[x] == 0 || generator[x] > i)
            generator[x] = i;
    }
    int y, T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &y);
        std::cout << generator[y] << std::endl;
    }
    // fclose(f);
    return 0;
}