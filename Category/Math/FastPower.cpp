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
