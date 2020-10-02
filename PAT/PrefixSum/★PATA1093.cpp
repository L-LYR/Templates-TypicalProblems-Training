#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<int> pos;
long long pcnt[maxn]; // pcnt[i] the number of 'P' in [i + 1, n].
long long tcnt[maxn]; // tcnt[i] the number of 'T' in [0, i - 1].

int main(void) {
    char c;
    int n = 0;
    int pend = 0;
    while (scanf("%c", &c) != EOF) {
        if (c == 'A') {
            pos.push_back(n);
        } else if (c == 'T') {
            tcnt[0]++;
            tcnt[n + 1]--;
        } else {
            pcnt[n + 1]++;
            pend--;
        }
        n++;
    }
    pcnt[n - 1] = pend;
    for (int i = 1; i < n; ++i) {
        pcnt[i] += pcnt[i - 1];
        tcnt[i] += tcnt[i - 1];
    }
    long long ans = 0;
    for (auto& i : pos) {
        ans = (ans + (tcnt[i] * pcnt[i]) % mod) % mod;
    }
    cout << ans << endl;

    return 0;
}