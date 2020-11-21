#include <bits/stdc++.h>
using namespace std;

auto main(void) -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0, c0 = 0, c1 = 0, h = 0;
        cin >> n >> c0 >> c1 >> h;
        auto bs = string();
        cin >> bs;
        // If the sum cost of changing and buying the opposite charactor
        // is cheaper than the cost of buying it directly, just do it!
        auto cnt = count_if(bs.begin(), bs.end(), [](char c) { return c == '1'; });
        cout << min(h + c1, c0) * (bs.length() - cnt) + min(h + c0, c1) * cnt << endl;
        // int ans = 0;
        // for (auto c : bs) {
        //     if (c == '0')
        //         ans += min(h + c1, c0);
        //     else
        //         ans += min(h + c0, c1);
        // }
        // cout << ans << endl;
    }

    return 0;
}