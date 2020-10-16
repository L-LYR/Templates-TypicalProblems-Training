#include <algorithm>
#include <cmath>
#include <iostream>
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

int main(void) {
    long n;
    cin >> n;
    get_prime(n);
    long ans = 0;
    for (int i = 1; i < prime.size(); ++i) {
        if (prime[i] - prime[i - 1] == 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}