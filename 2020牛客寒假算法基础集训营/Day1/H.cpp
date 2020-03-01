#include <iostream>

using namespace std;
const int maxn = 200005;
int cnt[maxn][2];
int n, k;

int main(void)
{
    scanf("%d %d", &n, &k);
    getchar();
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = getchar() - '0';
        cnt[i][c] = cnt[i - 1][c] + 1;
        c ^= 1;
        cnt[i][c] = cnt[i - 1][c];
    }
    int maxlen = 0;
    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n;
        while (l <= r)
        {
            int mid = ((r - l) >> 1) + l;
            if (min(cnt[mid][0] - cnt[i][0], cnt[mid][1] - cnt[i][1]) <= k)
            {
                l = mid + 1;
                maxlen = max(mid - i + 1, maxlen);
            }
            else
                r = mid - 1;
        }
    }

    printf("%d\n", maxlen);
    return 0;
}