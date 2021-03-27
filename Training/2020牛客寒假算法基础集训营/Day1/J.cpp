#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const ll module = 1e9 + 7;

ll fastPower(ll base, ll expo, ll mod)
{
    ll ans = 1;
    while (expo > 0)
    {
        if (expo & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        expo >>= 1;
    }
    return ans % mod;
}
// matrix fast exponentiation
struct Matrix
{
    const static int maxn = 3;
    ll mod;
    int n;
    ll m[maxn][maxn];
    Matrix(int n_ = maxn, ll mod_ = 1) { set(0, n_, mod_); }
    Matrix(ll e, int n_ = maxn, ll mod_ = 1) { set(e, n_, mod_); }
    void set(ll e, int n_, ll mod_)
    {
        n = n_;
        mod = mod_;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[i][j] = e;
    }
    Matrix operator*(const Matrix &r) const
    {
        Matrix res;
        res.n = n;
        res.mod = mod;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * r.m[k][j]) % mod;
        return res;
    }

    Matrix operator^(ll p)
    {
        Matrix ans, base = *(this);
        ans.n = n;
        ans.mod = mod;
        for (int i = 0; i < n; ++i)
            ans.m[i][i] = 1;
        while (p > 0)
        {
            if (p & 1)
                ans = ans * base;
            base = base * base;
            p >>= 1;
        }
        return ans;
    }
};

int main(void)
{
    ll n, x, y, a, b;
    scanf("%llu %llu %llu %llu %llu", &n, &x, &y, &a, &b);
    x %= module;
    y %= module;
    a %= module;
    ll ans;
    if (n == 1)
        ans = x;
    else if (n == 2)
        ans = y;
    else if (x == 0 || y == 0 || a == 0)
        ans = 0;
    else
    {
        Matrix unit(1, 2, module - 1);
        unit.m[1][1] = 0;
        unit = unit ^ (n - 2);
        ll ex_x = unit.m[0][1];
        ll ex_y = unit.m[0][0];

        unit.set(1, 3, module - 1);
        unit.m[1][1] = unit.m[1][2] =
            unit.m[2][0] = unit.m[2][1] = 0;
        unit = unit ^ (n - 4);
        ll ex_b = (2 * unit.m[0][0] + unit.m[0][1] + unit.m[0][2]) % (module - 1);

        a = fastPower(a, b, module);
        x = fastPower(x, ex_x, module);
        y = fastPower(y, ex_y, module);
        a = fastPower(a, ex_b, module);
        ans = x * y % module * a % module;
    }
    printf("%lld\n", ans);
    return 0;
}