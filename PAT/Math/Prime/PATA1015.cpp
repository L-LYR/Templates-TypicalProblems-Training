#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

bool is_prime[maxn];

vector<long> prime;

void get_prime(long n) {
    is_prime[0] = is_prime[1] = false;
    for (long i = 2; i <= n; ++i) is_prime[i] = true;
    for (long i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            if (i * i <= n) {
                for (long j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

int get_rev(int n, int base) {
    vector<int> si;
    while (n > 0) {
        si.push_back(n % base);
        n /= base;
    }
    int ans = 0;
    for (auto &i : si) {
        ans *= base;
        ans += i;
    }
    return ans;
}

int main(void) {
    get_prime(1e5);
    int n;
    int base;
    while (true) {
        cin >> n >> base;
        if (n < 0) break;
        int rn = get_rev(n, base);
        cout << rn << endl;
        if (is_prime[n] && is_prime[rn])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}