#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> primes;
const int maxn = 1e5 + 5;
bool is_prime[maxn];
void get_prime(long n) {
    is_prime[0] = is_prime[1] = false;
    for (long i = 2; i <= n; ++i) is_prime[i] = true;
    for (long i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (i * i <= n) {
                for (long j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}
// Quadratic probing
int main(void) {
    get_prime(100000);
    int m, n;
    cin >> m >> n;
    if (!is_prime[m]) {
        for (auto &i : primes) {
            if (i > m) {
                m = i;
                break;
            }
        }
    }
    int k;
    bool loc[m + 5];
    memset(loc, true, sizeof(loc));
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (i > 0) cout << " ";
        int l = k % m;
        if (loc[l]) {
            loc[l] = false;
            cout << l;
        } else {
            int step = 1;
            while (step < m) {
                int next = (k + step * step) % m;
                if (loc[next]) {
                    loc[next] = false;
                    cout << next;
                    break;
                }
                step++;
            }
            if (step >= m) {
                cout << '-';
            }
        }
    }
    cout << endl;

    return 0;
}