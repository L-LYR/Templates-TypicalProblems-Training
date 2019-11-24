#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N, M;
int ans = INT32_MAX;
void dfs(int depth, int r, int h, int v, int s)
{
    if (depth == M)
    {
        if (v == N && s < ans)
            ans = s;
        return;
    }
    int mri = r - 1;
    int mhi = h - 1;
    if (s + 2 * mri * mhi > ans)
        return;
    for (int ri = mri; ri >= M - depth; --ri)
    {
        int cmhi = min((N - v) / (ri * ri), h - 1);
        for (int hi = M - depth; hi <= cmhi; ++hi)
        {
            int si = 2 * ri * hi;
            int vi = ri * ri * hi;
            dfs(depth + 1, ri, hi, v + vi, s + si);
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for (int r = floor(sqrt(N)); r >= 1; --r)
    {
        int mh = N / (r * r);
        for (int h = mh; h >= 1; --h)
        {
            int s = r * r + 2 * r * h;
            int v = r * r * h;
            dfs(1, r, h, v, s);
        }
    }
    if (ans == INT32_MAX)
        cout << 0 << endl;
    else
        cout << ans << endl;
    return 0;
}