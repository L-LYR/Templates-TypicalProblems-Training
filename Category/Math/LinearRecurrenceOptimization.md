# 快速幂

一个简单的例子：$3^{13}$
$$
\begin{align}3^{13} &= 3^{(1101)_2}\\&=3^8\cdot3^4\cdot3\end{align}
$$

因此我们只需要计算$3,3^2,3^4,3^8$，然后依据$(1101)_2$来选择$3,3^4,3^8$相乘得出结果，计算幂指数只用到了$3$次运算，挑选需要4次。因此不难看出，两次操作的复杂度均为$O(\log n)$，其中$n$为指数。

## 快速幂&矩阵快速幂模板

```c++
using ll = long long;
ll fastPower(ll base, ll expo) // calculate base^expo
{
    ll ans = 1;
    while (expo > 0)
    {
        if (expo & 1)
            ans = ans * base;
        base = base * base;
        expo >>= 1;
    }
    return ans;
}

ll fastPower(ll base, ll expo, ll mod) // calculate base^expo % mod
{
    base %= mod;
    ll ans = 1;
    while (expo > 0)
    {
        if (expo & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        expo >>= 1;
    }
    return ans % mod; // important
}

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
        return ans;
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
```

## 应用

### 优化线性递推

例如求斐波那契数列的第$n$项：
$$
F_{n}=F_{n-2}+F_{n-1}
\\\Rightarrow 
\left[\begin{matrix}
F_{n} \\
F_{n-1}
\end{matrix}\right]=\left[\begin{matrix}
1 & 1 \\
1 & 0
\end{matrix}\right]\cdot\left[\begin{matrix}
F_{n-1} \\
F_{n-2}
\end{matrix}\right]
$$
设$M=\left[\begin{matrix}1 & 1 \\ 1 & 0\end{matrix}\right]$，则有
$$
\left[\begin{matrix}
F_{n} \\
F_{n-1}
\end{matrix}\right]=\left[\begin{matrix}
1 & 1 \\
1 & 0
\end{matrix}\right]^{n}\cdot\left[\begin{matrix}
F_{1} \\
F_{0}
\end{matrix}\right]= M^{n}\cdot\left[\begin{matrix}
F_{1} \\
F_{0}
\end{matrix}\right]
$$


依据快速幂我们可以在$O(\log n)$的时间内计算出$M^n$。

更一般的

> 给定k阶齐次线性递推式$a_n=\sum_{i=1}^k f_i a_{n-i}$，以及数列的前$k$项，求$a_n$。

考虑构造如下$k$阶方阵：
$$
\left[\begin{matrix}
f_1 & f_2 & f_3 & \cdots & f_{k-1} & f_k \\
1 & 0 & 0 & \cdots & 0 & 0 \\
0 & 1 & 0 & \cdots & 0 & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\ 
0 & 0 & 0 & \cdots & 1 & 0
\end{matrix}\right]
$$
以及初始向量：
$$
\left[\begin{matrix}
a_k\\
a_{k-1}\\
a_{k-2}\\
\vdots \\
a_1
\end{matrix}\right]
$$
可以得到结果：
$$
\left[\begin{matrix}
a_n\\
a_{n-1}\\
a_{n-2}\\
\vdots \\
a_{n-k+1}
\end{matrix}\right]=\left[\begin{matrix}
f_1 & f_2 & f_3 & \cdots & f_{k-1} & f_k \\
1 & 0 & 0 & \cdots & 0 & 0 \\
0 & 1 & 0 & \cdots & 0 & 0 \\
\vdots & \vdots & \vdots & \ddots & \vdots & \vdots \\ 
0 & 0 & 0 & \cdots & 1 & 0
\end{matrix}\right]^{n-1}\left[\begin{matrix}
a_k\\
a_{k-1}\\
a_{k-2}\\
\vdots \\
a_1
\end{matrix}\right]
$$

利用快速幂计算矩阵乘法，时间复杂度$O(k^3\log n)$。