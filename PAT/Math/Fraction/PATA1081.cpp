#include <algorithm>
#include <iostream>

using namespace std;

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    long a, b;
    frac(long x = 0, long y = 1) : a(x), b(y) {}
    frac operator+(const frac& r) const {
        frac ret;
        ret.a = r.a * b + r.b * a;
        ret.b = r.b * b;
        return ret.simplify();
    }
    friend istream& operator>>(istream& in, frac& f) {
        in >> f.a;
        in.ignore() >> f.b;
        return in;
    }
    friend ostream& operator<<(ostream& out, const frac& f) {
        out << f.a << '/' << f.b;
        return out;
    }
    frac simplify(void) {
        if (a == 0)
            b = 1;
        else {
            long d = gcd(abs(a), abs(b));
            a /= d;
            b /= d;
        }
        return *this;
    }
};

int main(void) {
    int n;
    cin >> n;
    frac ans, t;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        ans = ans + t;
    }
    int k = ans.a / ans.b;
    if (k || ans.a == 0)
        cout << k;
    ans.a = ans.a % ans.b;
    if (ans.a) {
        if (k) cout << " ";
        cout << ans;
    }
    cout << endl;
    return 0;
}