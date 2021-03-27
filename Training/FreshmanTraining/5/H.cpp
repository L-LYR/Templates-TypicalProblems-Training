#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 100005;
int a[maxn];
vector<pair<int, int>> e[maxn];

// int getsize(int k)
// {
//     if (e[k].size() == 0)
//         return 1;
//     int ret = 0;
//     for (auto i : e[k])
//         ret += getsize(i.first);
//     return ret + 1;
// }

int dfs(int curp, long long depth)
{
    if (depth > a[curp])
        return 0;
    int ret = 1;
    for (auto i : e[curp])
    {
        if (i.second + depth > 0)
            ret += dfs(i.first, i.second + depth);
        else
            ret += dfs(i.first, 0);
    }

    return ret;
}

int main(void)
{
    int n, p, c;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 2; i <= n; ++i)
    {
        cin >> p >> c;
        e[p].push_back({i, c});
    }
    cout << n - dfs(1, 0) << endl;
    return 0;
}