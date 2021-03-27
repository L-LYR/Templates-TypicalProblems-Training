#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; ++i) // enumerate
    {
        for (int j = 1; j <= i; ++j) // get all the factors
        {
            if (i * i % j == 0)
                ans += 2;
        }
        ans -= 1; // case i == j was calculated twice.
    }
    printf("%d\n", ans);
    return 0;
}