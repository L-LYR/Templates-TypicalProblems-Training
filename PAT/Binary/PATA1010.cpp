#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
map<char, ll> m;

ll get_num(string s, ll r) {
    ll ans = m[s[0]];
    for (int i = 1; i < s.length(); ++i) {
        ans = r * ans + m[s[i]];
    }
    return ans;
}

ll get_lower(string s) {
    ll ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        ret = max(ret, m[s[i]]);
    }
    return ret + 1;
}

void init(void) {
    for (char c = '0'; c <= '9'; ++c) {
        m[c] = c - '0';
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        m[c] = c - 'a' + 10;
    }
}

bool binary_search(ll l, ll r, ll target, string s) {
    while (l <= r) {
        ll m = (r - l) / 2 + l;
        ll n2 = get_num(s, m);
        if (n2 < 0 || n2 > target) {  // pay attention
            r = m - 1;
        } else if (n2 < target) {
            l = m + 1;
        } else {
            cout << m << endl;
            return true;
        }
    }
    return false;
}

int main(void) {
    init();
    string s1, s2;
    ll flag, r1;
    cin >> s1 >> s2 >> flag >> r1;
    if (flag == 2) swap(s1, s2);
    ll n1 = get_num(s1, r1);
    ll low = get_lower(s2);
    bool ret = binary_search(low, max(n1, low) + 1, n1, s2);
    if (!ret)
        cout << "Impossible" << endl;
    return 0;
}