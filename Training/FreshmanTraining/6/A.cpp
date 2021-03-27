#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 105;
vector<int> g[maxn];
int visit[maxn], cnt;
// bool dfs_loop(int cur, int father)
// {
//     visit[cur] = 1;
//     for (auto v : g[cur])
//     {
//         if (v == father)
//             continue;
//         if (visit[v] != 0 || dfs_loop(v, cur))
//             return true;
//     }
//     return false;
// }
void dfs_connect(int cur, int father)
{
    visit[cur] = 1;
    ++cnt;
    for (auto v : g[cur])
    {
        if (v != father && visit[v] == 0)
            dfs_connect(v, cur);
    }
}
int main(void)
{
    int n, m, bp, ep;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> bp >> ep;
        g[bp].push_back(ep);
        g[ep].push_back(bp);
    }
    // visit[1] = 1;
    // bool flag = dfs_loop(1, 0);
    // memset(visit, 0, sizeof(visit));
    visit[1] = 1;
    dfs_connect(1, 0);
    if (n == m && cnt == m)
        cout << "FHTAGN!" << endl;
    else
        cout << "NO" << endl;
    return 0;
}