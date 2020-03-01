#include <queue>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2e5 + 5;
struct item
{
    int sum;
    int id;
} g[maxn];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> g[i].sum;
    for (int i = 1, tmp; i <= n; ++i)
    {
        cin >> tmp;
        g[i].sum += tmp;
        g[i].id = i;
    }
    sort(g + 1, g + n + 1, [](const item &l, const item &r) -> bool {
        return l.sum > r.sum;
    });
    for (int i = 1; i <= n; i += 2)
        printf("%d ", g[i].id);
    printf("\n");
    for (int i = 2; i <= n; i += 2)
        printf("%d ", g[i].id);

    return 0;
}