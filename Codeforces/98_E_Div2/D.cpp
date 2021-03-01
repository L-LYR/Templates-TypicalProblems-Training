#include <bits/stdc++.h>
using namespace std;

const auto mod = 998244353;

// x ^ p % mod
auto fp(long long x, long long p) -> long long {
    auto ans = 1ll;
    while (p > 0) {
        if (p & 1) ans = ans * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ans;
}

// m is prime and a, m are coprime
// a^(m - 1) === 1(mod m) => a * a^(m-2) === 1(mod m)
// inv(a, m) = a^(m - 2)
auto inv(long long x) -> long long {
    return fp(x, mod - 2);
}

// bx === 1(mod m)
// (a / b) mod m = a * inv(b) mod m
auto pro(long long a, long long b) -> long long {
    return a * inv(b) % mod;
}

// The problem can be reduce into a more explicit one.
// Calculate the number of cases that dividing n into
// the sum of sequential odd numbers.
// For example:
// 5 = 5 = 1 + 1 + 3 = 1 + 3 + 1 = 3 + 1 + 1 = 1 + 1 + 1 + 1 + 1
// This number of cases of n is actually Fibonacci(n).
// So the probability of this problem is reduced into  F(n) / 2 ^ n.
auto main() -> int {
    auto n = 0;
    cin >> n;
    auto Fi_1 = 0ll, Fi = 1ll;
    for (auto i = 2; i <= n; ++i) {
        auto tmp = Fi;
        Fi = (Fi_1 + tmp) % mod;
        Fi_1 = tmp;
    }
    // cout << Fi << " " << fp(2, n) << endl;
    cout << pro(Fi, fp(2, n)) << endl;
    return 0;
}