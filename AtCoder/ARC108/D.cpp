#include <bits/stdc++.h>
using namespace std;

const auto mod = 1000000007;

auto fp(long long x, long long e) -> long long {
    auto ans = 1ll;
    while (e > 0) {
        if (e & 1) ans = ans * x % mod;
        e >>= 1;
        x = x * x % mod;
    }
    return ans;
}

auto fib(int n) -> long long {
    auto Fi_1 = 1ll, Fi = 1ll;
    while (--n > 0) {
        auto tmp = Fi;
        Fi = (Fi_1 + Fi) % mod;
        Fi_1 = tmp;
    }
    return Fi;
}
// The original string is 'AB' and the first step is fixed, Cab.
// The if-statements below are all based on the condition that Cab = 'A'.
// If Caa = 'A', the string will be only one possible case: A...AB.
// If Caa = 'B' and Cba = 'B', the strings will be the patterns like below:
// AAB -> ABAB -> ABBAB -> ...
//     -> AAAB -> ABAAB
//             -> AAAAB
//             -> AABAB
// Pattern: A...AB (... can be the combination of A and B.).
// So the number of cases will be 2^(n-3).
// If Caa = 'B' and Cba = 'A', the string will be the pattern like below:
// AAB -> ABAB -> ABAAB -> ...
//     -> AAAB -> AABAB
//             -> AAAAB
// Cbb will not influence the last two sequences.
// If Cab = 'B', just like the cases above.
auto main() -> int {
    auto n = 0;
    auto AA = char{}, AB = char{},
         BA = char{}, BB = char{};
    cin >> n;
    cin >> AA >> AB >> BA >> BB;
    if (n <= 3) {
        cout << 1 << endl;
        return 0;
    }
    if (AB == 'A') {
        if (AA == 'A') {
            cout << 1 << endl;
        } else if (BA == 'B') {
            cout << fp(2, n - 3) << endl;
        } else {
            cout << fib(n - 2) << endl;
        }

    } else {
        if (BB == 'B') {
            cout << 1 << endl;
        } else if (BA == 'A') {
            cout << fp(2, n - 3) << endl;
        } else {
            cout << fib(n - 2) << endl;
        }
    }
    return 0;
}