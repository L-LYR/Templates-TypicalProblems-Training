#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 200005;

int main(void)
{
    int n, k, minlen;
    scanf("%d %d", &n, &k);
    getchar();
    minlen = n + 1;
    vector<int> cnt[26];

    for (int i = 0; i < n; ++i)
    {
        char c;
        scanf("%c", &c);
        cnt[c - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; ++i)
        if (cnt[i].size() >= k)
        {
            int lim = cnt[i].size() + 1 - k;
            for (int j = 0; j < lim; ++j)
                minlen = min(minlen, cnt[i][j + k - 1] - cnt[i][j] + 1);
        }

    if (minlen == n + 1)
        printf("-1\n");
    else
        printf("%d\n", minlen);

    return 0;
}