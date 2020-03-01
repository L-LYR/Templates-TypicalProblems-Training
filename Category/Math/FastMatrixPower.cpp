// luogu P3390: https://www.luogu.com.cn/problem/P3390
// Fast Matrix Power
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
using ll = long long;
// #define DEBUG

struct Matrix
{
    static const int maxn = 105;
    static const ll mod = 1e9 + 7;
    int n;
    ll val[maxn][maxn];
    Matrix() { setZero(); }
    void setZero() { memset(val, 0, sizeof(val)); }

    Matrix operator*(const Matrix &r) const
    {
        Matrix res;
        res.n = n;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    res.val[i][j] =
                        (res.val[i][j] + val[i][k] * r.val[k][j]) % mod;
        // res.val += val[i][k] * r.val[k][j];
        return res;
    }

    Matrix operator%(ll m)
    {
        Matrix res;
        res.n = n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res.val[i][j] = val[i][j] % m;
        return res;
    }

    Matrix operator^(ll p)
    {
        Matrix base = *this, ans;
        ans.n = n;
        for (int i = 0; i < n; ++i)
            ans.val[i][i] = 1;
        while (p)
        {
            if (p & 1)
                ans = ans * base;
            base = base * base;
            p >>= 1;
        }
        return ans % mod;
    }
};
istream &operator>>(istream &in, Matrix &m)
{
    for (int i = 0; i < m.n; ++i)
        for (int j = 0; j < m.n; ++j)
            in >> m.val[i][j];
    return in;
}
ostream &operator<<(ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.n; ++i)
    {
        out << m.val[i][0];
        for (int j = 1; j < m.n; ++j)
            out << " " << m.val[i][j];
        out << endl;
    }
    return out;
}
int main(void)
{
#ifdef DEBUG
    freopen("./input", "r", stdin);
    freopen("./output", "w", stdout);
#endif
    int n;
    ll k;
    cin >> n >> k;
    Matrix m;
    m.n = n;
    cin >> m;
    cout << (m ^ k);
    return 0;
}