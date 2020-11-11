#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 105;

int n, arr[maxn];
int main(void) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    map<int, int> cnt;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[j] % i == 0) cnt[i]++;
        }
    }
    cout << max_element(cnt.begin(), cnt.end(), [](const pii &l, const pii &r) {
                return l.second < r.second;
            })->first
         << endl;
    return 0;
}