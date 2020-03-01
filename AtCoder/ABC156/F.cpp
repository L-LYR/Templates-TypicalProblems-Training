#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int maxn = 5010;
vector<ll> d(maxn), sum(maxn), cnt(maxn);
int k, q, n, x, m;
int main(void)
{
    scanf("%d%d", &k, &q);
    for (int i = 0; i < k; ++i)
        scanf("%lld", &d[i]);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d%d%d", &n, &x, &m);

        vector<ll> dm(d);
        sum[0] = 0;
        cnt[0] = 0;
        for (int j = 0; j < k; ++j)
        {
            dm[j] %= m;
            sum[j + 1] = sum[j] + dm[j];
            cnt[j + 1] = cnt[j] + (dm[j] == 0);
        }

        ll loop = (n - 1) / k;
        ll remain = (n - 1) % k;
        ll ans = (n - 1) -
                 (loop * cnt[k] + cnt[remain]) -
                 (loop * sum[k] + sum[remain] + x) / m + x / m;
        printf("%d\n", ans);
    }
    return 0;
}