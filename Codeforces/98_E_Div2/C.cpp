#include <bits/stdc++.h>
using namespace std;

auto main(void) -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto s = string();
        cin >> s;
        auto ans = 0;
        auto sl = stack<char>();
        auto sb = stack<char>();
        for (auto c : s) {
            if (c == '(') sl.push(c);
            if (c == ')' && !sl.empty() && sl.top() == '(') {
                sl.pop();
                ans++;
            }
            if (c == '[') sb.push(c);
            if (c == ']' && !sb.empty() && sb.top() == '[') {
                sb.pop();
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}