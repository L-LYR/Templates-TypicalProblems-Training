#include <algorithm>
#include <iostream>

using namespace std;

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    long a, b;
    frac(int _a = 0, int _b = 1) : a(_a), b(_b) {}

    frac simplify(void) {
        if (b == 0) {
            a = 0;
            return *this;
        }
        if (b < 0) {
            a = -a;
            b = -b;
        }
        if (a == 0)
            b = 1;
        else {
            long d = gcd(abs(a), abs(b));
            a /= d;
            b /= d;
        }
        return *this;
    }

    frac operator+(const frac& r) const {
        frac ret;
        ret.a = a * r.b + b * r.a;
        ret.b = b * r.b;
        return ret.simplify();
    }
    frac operator-(const frac& r) const {
        frac ret;
        ret.a = a * r.b - b * r.a;
        ret.b = b * r.b;
        return ret.simplify();
    }
    frac operator*(const frac& r) const {
        frac ret;
        ret.a = a * r.a;
        ret.b = b * r.b;
        return ret.simplify();
    }
    frac operator/(const frac& r) const {
        frac ret;
        ret.a = a * r.b;
        ret.b = b * r.a;
        return ret.simplify();
    }

    friend istream& operator>>(istream& in, frac& f) {
        in >> f.a;
        in.ignore() >> f.b;
        return in;
    }

    friend ostream& operator<<(ostream& out, frac f) {
        f.simplify();
        if (f.b == 0) {
            out << "Inf";
        } else if (f.a == 0)
            out << 0;
        else {
            if (f.a < 0) out << "(";
            long d = f.a / f.b;
            long r = f.a % f.b;
            if (d) out << d;
            if (r && d) out << " ";
            if (r) {
                if (d < 0)
                    out << abs(r);
                else
                    out << r;
                out << "/" << f.b;
            }
            if (f.a < 0) cout << ")";
        }
        return out;
    }
};

int main(void) {
    frac x, y;
    cin >> x >> y;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    return 0;
}