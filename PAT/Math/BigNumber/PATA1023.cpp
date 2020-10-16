#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string num;
    cin >> num;
    int len = num.length();
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    vector<int> n(len, 0);
    for (int i = 0; i < len; ++i) {
        n[len - 1 - i] = (num[i] - '0') * 2;
        cnt[num[i] - '0']++;
    }
    vector<int> ans(len + 1, 0);
    for (int i = len - 1; i >= 0; --i) {
        ans[i + 1] += n[i] / 10;
        ans[i] += n[i] % 10;
    }
    for (int i = 0; i < len; ++i) {
        cnt[ans[i]]--;
    }
    if (ans[len] != 0) {
        cnt[ans[len]]--;
    }
    bool flag = true;
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] != 0) {
            flag = false;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    if (ans[len] != 0) cout << ans[len];
    for (int i = len - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}