#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
long long query(long long ql, long long qr, long long n, long long l, long long r)
{
    if (l == r)
        return n; // n is 1 or 0.
    long long ret = 0;
    long long mid = l + ((r - l) >> 1);
    if (ql < mid)
        ret += query(ql, qr, n / 2, l, mid);
    if (qr > mid)
        ret += query(ql, qr, n / 2, mid + 1, r);
    if (mid >= ql && mid <= qr)
        ret += n % 2;
    return ret;
}
int main(void)
{
    long long n, l, r;
    cin >> n >> l >> r;
    long long len = pow(2, ceil(log2(n + 1)));
    cout << query(l, r, n, 1, len) << endl;
    return 0;
}

