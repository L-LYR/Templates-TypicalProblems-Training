#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;
int v[maxn];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    sort(v, v + n);
    n = unique(v, v + n) - v;
    // To find the minimum of k value that there exists
    // v[i]'s k-th bit is 0 and v[j]'s k-th bit is 1.
    // If v[n]'s k-th bit is 1,
    // then we have lowbit(v[n] ^ v[i]) = 1 << k,
    // and similarly, if v[n]'s k-th bit is 0,
    // we have lowbit(v[n] ^ v[j]) = 1 << k.
    // So the answer is (1 << k) * (n - 1)
    int va = 0xFFFFFFFF, vo = 0;
    for (int i = 0; i < n; ++i)
    {
        va &= v[i];
        vo |= v[i];
    }
    int vx = va ^ vo, lowbit = 0;
    for (int i = 0; i <= 30; ++i)
    {
        lowbit = 1 << i;
        if (lowbit & vx)
            break;
    }
    printf("%lld\n", lowbit * (n - 1));
    return 0;
}