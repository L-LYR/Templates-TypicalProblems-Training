#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
int parent[maxn];
// 并查集判环、判连通
void init(void)
{
    for (int i = 0; i < maxn; ++i)
        parent[i] = i;
}

int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }

// void merge(int x, int y)
// {
//     x = find(x);
//     y = find(y);
//     if (x != y)
//         parent[x] = y;
// }

int main(void)
{
    int n, m, bp, ep;
    cin >> n >> m;
    init();
    int hasCircle = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> bp >> ep;
        int pb = find(bp), pe = find(ep);
        if (pb == pe)
            ++hasCircle;
        parent[pb] = parent[pe];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (parent[i] == i)
            ++cnt;
    if (hasCircle == 1 && cnt == 1)
        cout << "FHTAGN!" << endl;
    else
        cout << "NO" << endl;
    return 0;
}