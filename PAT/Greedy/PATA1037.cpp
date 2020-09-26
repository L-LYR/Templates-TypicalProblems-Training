#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(void)
{
    int n, in, m;
    cin >> n;
    vector<int> cp, pp, cn, pn;
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        if (in > 0)
            cp.push_back(in);
        else
            cn.push_back(in);
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> in;
        if (in > 0)
            pp.push_back(in);
        else
            pn.push_back(in);
    }
    sort(cp.begin(), cp.end(), greater<int>());
    sort(pp.begin(), pp.end(), greater<int>());
    sort(cn.begin(), cn.end());
    sort(pn.begin(), pn.end());

    ll ans = 0;
    // product between bigger-absolute-value ones with the same sign
    for (int i = 0; i < cp.size() && i < pp.size(); ++i)
        ans += cp[i] * pp[i];
    for (int i = 0; i < cn.size() && i < pn.size(); ++i)
        ans += cn[i] * pn[i];

    cout << ans << endl;
    return 0;
}