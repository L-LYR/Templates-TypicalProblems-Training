#include <iostream>
using namespace std;
int main(void)
{
    int ps, pg, pk;
    cin >> pg;
    cin.ignore(1) >> ps;
    cin.ignore(1) >> pk;
    int S, G, K;
    cin >> G;
    cin.ignore(1) >> S;
    cin.ignore(1) >> K;
    pk += (pg * 17 + ps) * 29;
    K += (G * 17 + S) * 29;
    K -= pk;
    if (K < 0)
    {
        cout << "-";
        K = -K;
    }
    S = K / 29;
    K %= 29;

    G = S / 17;
    S %= 17;

    cout << G << "."
         << S << "."
         << K << endl;
    return 0;
}