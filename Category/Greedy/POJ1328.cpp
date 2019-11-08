#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct island
{
    double l, r;
};
const int maxn = 1005;
island isd[maxn];
bool cmp(const island &a, const island &b)
{
    return a.l < b.l;
}

int main(void)
{
    int n, d, flag = 0, cases = 1, x, y;
    while (cin >> n >> d && n != 0)
    {
        flag = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            if (y > d)
                flag = 1;
            //preprocess and we will sort by the interval left bound
            isd[i].l = x - sqrt(d * d - y * y);
            isd[i].r = x + sqrt(d * d - y * y);
        }

        cout << "Case " << cases++ << ": ";
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }
        // important !
        // this sort determines the correct answer of this greedy algorithm
        sort(isd, isd + n, cmp);

        int cnt = 1;
        double xk = isd[0].r;
        for (int i = 1; i < n; ++i)
        {
            if (isd[i].l > xk)
            {
                xk = isd[i].r;
                ++cnt;
            }
            else
                xk = min(xk, isd[i].r); //attention!
                                        //shrink the range to fit
        }
        cout << cnt << endl;
    }
    return 0;
}