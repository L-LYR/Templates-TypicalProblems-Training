#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int m, n, nums[10] = {0}, ans;
void find(int i, int depth)
{
    if (depth == n)
    {
        ans++;
        return;
    }
    for (int j = i - 2; j <= i + 2; ++j)
    {
        if (j >= 0 && j <= 9 && nums[j])
            find(j, depth + 1);
    }
}

int main(void)
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        memset(nums, 0, sizeof(nums));
        cin >> m >> n;
        for (int i = 0, j; i < m; ++i)
        {
            cin >> j;
            nums[j] = 1;
        }
        ans = 0;
        for (int i = 1; i <= 9; ++i)
            if (nums[i])
                find(i, 1);
        cout << "Case " << t << ": " << ans << endl;
    }

    return 0;
}