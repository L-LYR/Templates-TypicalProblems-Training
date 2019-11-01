#include <iostream>
using namespace std;

int main(void)
{
    int G, S, K;
    cin >> G;
    cin.ignore(1) >> S;
    cin.ignore(1) >> K;
    int temp;
    cin >> temp;
    G += temp;
    cin.ignore(1) >> temp;
    S += temp;
    cin.ignore(1) >> temp;
    K += temp;
    S += K / 29;
    K %= 29;
    G += S / 17;
    S %= 17;
    cout << G << '.' << S << '.' << K << endl;
    return 0;
}