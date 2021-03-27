#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

const int maxn = 1005;

int t[maxn];
long long num[maxn];
set<int> home;

void init(void)
{
    for (int i = 0; i < maxn; ++i)
    {
        t[i] = i;
        num[i] = 1;
    }
}

int find(int x) { return t[x] == x ? x : (t[x] = find(t[x])); }

void merge(int bp, int ep)
{
    int pb = find(bp), pe = find(ep);
    if (pb != pe)
    {
        if (home.count(pb))
            swap(pb, pe);
        t[pb] = t[pe];
        num[pe] += num[pb];
    }
}

int main(void)
{
    init();

    int n, m, k, h, bp, ep;
    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i)
    {
        cin >> h;
        home.insert(h);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> bp >> ep;
        merge(bp, ep);
    }

    // int p = find(*(home.begin()));

    int p = 0, maxNum = 0;
    for (auto i : home)
        if (num[i] > maxNum)
        {
            p = i;
            maxNum = num[i];
        }

    for (int i = 1; i <= n; ++i)
    {
        if (t[i] == i && home.count(i) != 1)
        {
            t[i] = p;
            num[p] += num[i];
        }
    }

    long long ans = 0;
    for (auto i : home)
        ans += ((num[i] - 1) * num[i]) / 2;
    cout << ans - m << endl;

    return 0;
}