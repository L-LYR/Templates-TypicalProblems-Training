#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
bool is_prime[maxn];
vector<long> primes;

void get_prime(int n) {
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

int main(void) {
    int m, n;
    cin >> m >> n;
    get_prime(1e5);
    m--;
    n--;

    int cnt = 0;
    for (int i = m; i <= n; ++i) {
        cout << primes[i];
        if (cnt == 9) {
            cout << endl;
            cnt = 0;
        } else {
            if (i < n)
                cout << " ";
            cnt++;
        }
    }
    return 0;
}