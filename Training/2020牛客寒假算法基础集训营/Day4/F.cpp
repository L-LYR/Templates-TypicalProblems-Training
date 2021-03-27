#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
vector<int> t[maxn];
ll odd, even;
void dfs(int x, int dep)
{
    (dep % 2) ? odd++ : even++;
    int len = t[x].size();
    for (int i = 0; i < len; ++i)
        dfs(t[x][i], dep + 1);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 2, p; i <= n; ++i)
    {
        scanf("%d", &p);
        t[p].push_back(i);
    }
    if (n > 0)
        dfs(1, 0);
    ll ans = odd * (odd - 1) + even * (even - 1); // they cannot be adjacent
    printf("%lld\n", ans);

    return 0;
}