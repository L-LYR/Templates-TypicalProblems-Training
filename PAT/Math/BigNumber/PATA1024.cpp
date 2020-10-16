#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const vector<int> &n) {
    for (int i = 0, j = n.size() - 1; i <= j; ++i, --j) {
        if (n[i] != n[j]) return false;
    }
    return true;
}

int main(void) {
    string num;
    int k;
    cin >> num >> k;
    int len = num.length();
    vector<int> n(len);
    for (int i = 0; i < len; ++i) {
        n[i] = num[i] - '0';
    }
    int i;
    for (i = 0; i < k; ++i) {
        if (isPalindrome(n)) {
            break;
        }
        len = n.size();
        int c = 0;
        vector<int> ans(len, 0);
        for (int i = 0, j = len - 1; i < len; ++i, --j) {
            int sum = n[i] + n[j] + c;
            ans[j] += sum % 10;
            c = sum / 10;
        }
        if (c == 1) ans.insert(ans.begin(), c);
        swap(ans, n);
        // reverse(n.begin(), n.end());
        // for (auto c : n) {
        //     cout << c;
        // }
        // cout << endl;
    }

    for (auto c : n) {
        cout << c;
    }
    cout << endl;
    cout << i << endl;

    return 0;
}

/*
string s;
void add(const string& t) {
    int c = 0;
    for (int i = t.length() - 1; i >= 0; i--) {
        s[i] = s[i] + t[i] + c - '0';
        if (s[i] > '9') {
            s[i] -= 10;
            c = 1;
        } else {
            c = 0;
        }
    }
    if (c == 1) s.insert(s.begin(), '1');
}
int main() {
    int k, i;
    cin >> s >> k;
    for (i = 0; i <= k; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t || i == k) break;
        add(t);
        cout << s << endl;
    }
    cout << s << endl
         << i << endl;
    return 0;
}
*/