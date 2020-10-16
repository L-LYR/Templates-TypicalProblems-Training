#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;

bool isPrime[maxn];
vector<long long> primes;
void get_prime(long long n) {
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i <= n; ++i) isPrime[i] = true;
    for (long long i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            if (i * i < n) {
                for (long long j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}

map<int, int> cnt;

int main(void) {
    get_prime(1e6);

    long long n, m;
    cin >> n;

    if (n == 1) {
        cout << "1=1" << endl;
        return 0;
    }

    m = n;
    for (const auto& i : primes) {
        while (m > 1 && m % i == 0) {
            m /= i;
            cnt[i]++;
        }
    }
    int c = 0;
    cout << n << "=";
    for (const auto& i : cnt) {
        if (c) cout << "*";
        cout << i.first;
        if (i.second > 1) {
            cout << "^" << i.second;
        }
        c++;
    }
    cout << endl;

    return 0;
}