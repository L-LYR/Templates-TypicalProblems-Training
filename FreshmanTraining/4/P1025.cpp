#include <iostream>
using namespace std;

int ans, n, k;

void dfs(int depth, int num)
{
    if (depth == k && n >= num)
        ++ans;
    else
    {
        for (int i = num; i < n; ++i)
        {
            n -= i;
            dfs(depth + 1, i);
            n += i;
        }
    }
}

int main(void)
{
    cin >> n >> k;
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}