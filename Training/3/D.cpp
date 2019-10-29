#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int l, n, cases;
    scanf("%d", &cases);
    while (--cases >= 0)
    {
        scanf("%d %d", &n, &l);
        vector<int> len(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &len[i]);
        sort(len.begin(), len.end());
        int cnt = 0;
        while (!len.empty())
        {
            auto p = upper_bound(len.begin() + 1, len.end(), l - len[0]) - 1;
            if (p != len.begin())
                len.erase(p);
            len.erase(len.begin());
            cnt++;
        }
        cout << cnt << endl;
        if (cases != 0)
            cout << endl;
    }
    return 0;
}