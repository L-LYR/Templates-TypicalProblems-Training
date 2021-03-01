#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
    auto n = 0;
    auto s = string();
    cin >> n >> s;
    auto cs = stack<char>();
    auto cnt = 0;
    // Just use stack or another string.
    for (auto c : s) {
        switch (c) {
            case 'f':
                cs.push(c);
                continue;
            case 'o':
                if (!cs.empty() and cs.top() == 'f') {
                    cs.push(c);
                    continue;
                } else {
                    break;
                }
            case 'x':
                if (!cs.empty() and cs.top() == 'o') {
                    cs.pop();
                    if (!cs.empty() and cs.top() == 'f') {
                        cnt++;
                        cs.pop();
                        continue;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
        }
        while (!cs.empty()) cs.pop();
    }
    cout << n - cnt * 3 << endl;

    return 0;
}