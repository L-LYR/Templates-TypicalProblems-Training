#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using matrix = vector<vector<double>>;

inline matrix make(int n, int m, double k) { return matrix(n, vector<double>(m, k)); }

double det(const matrix &a)
{
    int n = a.size();
    if (n == 1)
        return a[0][0];

    double res = 0;
    matrix t = make(n - 1, n - 1, 0);
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1; ++j)
                t[i][j] = a[i + 1][(j >= k) ? j + 1 : j];
        double d = det(t);
        if (k % 2)
            res += a[0][k] * d;
        else
            res -= a[0][k] * d;
    }
    return res;
}

matrix inverse(const matrix &a)
{
    int n = a.size();
    double da = abs(det(a));
    matrix res = make(n, n, 0), t = make(n - 1, n - 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            for (int p = 0; p < n - 1; ++p)
                for (int q = 0; q < n - 1; ++q)
                    t[p][q] = a[(p >= i) ? p + 1 : p][(q >= j) ? q + 1 : q];
            res[j][i] = det(t);
            if ((i + j) % 2 == 0)
                res[j][i] *= -1;
            res[j][i] /= da;
        }
    return res;
}

matrix transpose(const matrix &a)
{
    int n = a.size(), m = a[0].size();
    matrix res = make(m, n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[j][i] = a[i][j];
    return res;
}

matrix operator*(const matrix &l, const matrix &r)
{
    int n = l.size(), m = l[0].size(), p = r[0].size();
    matrix res = make(n, p, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < p; ++j)
            for (int k = 0; k < m; ++k)
                res[i][j] += l[i][k] * r[k][j];
    return res;
}

matrix LU_inverse(const matrix &a)
{
    int n = a.size();
    matrix L = make(n, n, 0), U = make(n, n, 0);
    for (int i = 0; i < n; ++i)
    {
        L[i][i] = 1;
        U[0][i] = a[0][i];
    }
    for (int i = 1; i < n; ++i)
        L[i][0] = a[i][0] / U[0][0];

    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            double s = 0;
            for (int k = 0; k < i; ++k)
                s += L[i][k] * U[k][j];
            U[i][j] = a[i][j] - s;
        }
        for (int j = i; j < n; ++j)
        {
            double s = 0;
            for (int k = 0; k < i; ++k)
                s += L[j][k] * U[k][i];
            L[j][i] = (a[j][i] - s) / U[i][i];
        }
    }
    matrix L_inv = make(n, n, 0), U_inv = make(n, n, 0);
    for (int j = 0; j < n; ++j)
        for (int i = j; i < n; ++i)
            if (i == j)
                L_inv[i][j] = 1 / L[i][j];
            else if (i < j)
                L_inv[i][j] = 0;
            else
            {
                double s = 0;
                for (int k = j; k < i; ++k)
                    s += L[i][k] * L_inv[k][j];
                L_inv[i][j] = -L_inv[j][j] * s;
            }

    for (int j = 0; j < n; ++j)
        for (int i = j; i >= 0; --i)
            if (i == j)
                U_inv[i][j] = 1 / U[i][j];
            else if (i > j)
                U_inv[i][j] = 0;
            else
            {
                double s = 0;
                for (int k = i + 1; k <= j; ++k)
                    s += U[i][k] * U_inv[k][j];
                U_inv[i][j] = -1 / U[i][i] * s;
            }

    return U_inv * L_inv;
}

int main()
{
    int m, n;
    cin >> m >> n;

    matrix x = make(n, m + 1, 1);
    matrix y = make(n, 1, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> x[i][j];
        cin >> y[i][0];
    }

    matrix xt = transpose(x);
    matrix xtx = xt * x;
    matrix b = LU_inverse(xtx) * xt * y;

    int q;
    cin >> q;
    matrix v = make(1, m + 1, 1);
    for (int i = 0; i < q; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cin >> v[0][j];
        cout << (v * b)[0][0] << endl;
    }

    return 0;
}
/*
2 5
5 7 10
6 6 20
7 4 60
8 5 40
9 6 50
1
5 5
*/