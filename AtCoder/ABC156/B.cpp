#include <iostream>
using namespace std;

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    while (n > 0)
    {
        n /= k;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}