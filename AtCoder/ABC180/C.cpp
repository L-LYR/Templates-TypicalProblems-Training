#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> ans;

void getAllFactor(ll a) {
    if (a < 2) return;
    for (ll i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            ll r = a / i;
            ans.push_back(i);
            if (r != i)
                ans.push_back(a / i);
        }
    }
}

int main(void) {
    ll n;
    cin >> n;
    ans.push_back(1);
    if (n != 1)
        ans.push_back(n);
    getAllFactor(n);
    sort(ans.begin(), ans.end());
    for (const auto& i : ans) {
        cout << i << endl;
    }

    return 0;
}