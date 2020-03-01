#include <iostream>
#include <cstring>
#include <map>
using namespace std;
const int maxn = 25;
bool isPrime[maxn];
int cnt[maxn];
void init(int n)
{
    for (int i = 2; i <= n; ++i)
        isPrime[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

void getCnt(int n)
{
    for (int i = 2; i <= n; ++i)
    {
        if (!isPrime[i])
        {
            cnt[i]++;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    if (!isPrime[j])
                        cnt[i]++;
                    if (!isPrime[i / j] && j * j != i)
                        cnt[i]++;
                }
            }
        }
    }
}

int main(void)
{
    int n, m, k;
    scanf("%d %d", &n, &m);
    init(n);
    getCnt(n);
    map<int, int> ans;
    for (int i = 0; i <= n; ++i)
        ans[cnt[i]]++;

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }

    return 0;
}