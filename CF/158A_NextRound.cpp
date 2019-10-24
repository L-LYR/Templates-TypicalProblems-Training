#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, k, count, cur, last, kth;
    while (cin >> n >> k)
    {
        count = 0;
        int i;
        for (i = 0; i < k; ++i)
        {
            cin >> cur;
            if (cur == 0)
                break;
            ++count;
        }
        while (cur != 0 && i < n)
        {
            last = cur;
            cin >> cur;
            if (last == cur)
                ++count;
            else
                break;
            ++i;
        }
        while (++i < n)
            cin >> cur;
        cout << count << endl;
    }
    return 0;
}