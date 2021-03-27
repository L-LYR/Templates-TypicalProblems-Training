#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 200005;
vector<int> g[maxn];
int color[maxn];
bool visit[maxn];

void dfs(int cur, int pre)
{
    int cnt = 1;
    for (auto i : g[cur])
    {
        if (i == pre)
            continue;                                  //not cur-node's father
        while (cnt == color[cur] || cnt == color[pre]) //different color with his fathers
            ++cnt;
        color[i] = cnt++;
    }
    for (auto i : g[cur]) //dfs
    {
        if (i == pre)
            continue;
        dfs(i, cur);
    }
}

int main(void)
{
    int n, bp, ep;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> bp >> ep;
        g[bp].push_back(ep);
        g[ep].push_back(bp);
    }
    color[1] = 1;
    dfs(1, 0);
    int maxNum = 0;
    for (int i = 1; i <= n; ++i)
        maxNum = max(maxNum, color[i]);
    cout << maxNum << endl;

    for (int i = 1; i < n; ++i)
        cout << color[i] << " ";
    cout << color[n] << endl;

    return 0;
}