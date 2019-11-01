#include <bits/stdc++.h>
using namespace std;
#define MAX 105

struct BigNumber
{
    static const int base = 100000000;
    static const int width = 8;
    vector<int> n;

    BigNumber(long long num = 0) { *this = num; }
    BigNumber operator=(long long num)
    {
        n.clear();
        do
        {
            n.push_back(num % base);
            num /= base;
        } while (num);
        return *this;
    }
    BigNumber operator=(const string &str)
    {
        n.clear();
        int x, len = (str.length() - 1) / width + 1;
        for (int i = 0; i < len; ++i)
        {
            int end = str.length() - i * width;
            int start = max(0, end - width);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            n.push_back(x);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const BigNumber &x)
    {
        int size = x.n.size();
        out << x.n.back();
        for (int i = size - 2; i >= 0; --i)
            out << setw(width) << setfill('0') << x.n[i];
        return out;
    }
    friend istream &operator>>(istream &in, const BigNumber &x)
    {
        string s;
        if (!(in >> s))
            return in;
        x = s;
        return in;
    }

    BigNumber operator+(const BigNumber &b) const
    {
        BigNumber c;
        c.n.clear();
        int i = 0, g = 0;
        while (true)
        {
            if (g == 0 && i >= n.size() && i >= b.n.size())
                break;
            int x = g;
            if (i < n.size())
                x += n[i];
            if (i < b.n.size())
                x += b.n[i];
            c.n.push_back(x % base);
            g = x / base;
        }
        return c;
    }

    BigNumber operator-(const BigNumber &b) const
    {
        BigNumber c;
        c.n.clear();
        
    }
};

BigNumber dp[2][MAX];

BigNumber DP(int n, int k)
{
    BigNumber sum;
    dp[0][0] = 0;
    dp[1][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum = dp[0][i - 1] + dp[1][i - 1];
        dp[0][i] = sum;
        if (i <= k)
            dp[1][i] = sum;
        else if (i == k + 1)
            dp[1][i] = sum - 1;
        else
            dp[1][i] = sum - dp[0][i - k - 1];
    }
    return dp[1][n] + dp[0][n];
}

int main(void)
{
    int n, k;
    while (cin >> n >> k)
        cout << (DP(n, n) - DP(n, k - 1)) << endl;
    return 0;
}