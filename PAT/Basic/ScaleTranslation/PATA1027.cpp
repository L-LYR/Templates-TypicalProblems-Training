#include <iostream>
using namespace std;
const char radix[] =
    {'0', '1', '2', '3', '4', '5', '6',
     '7', '8', '9', 'A', 'B', 'C'};

int main(void)
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << '#' << radix[r / 13] << radix[r % 13]
         << radix[g / 13] << radix[g % 13]
         << radix[b / 13] << radix[b % 13] << endl;
    return 0;
}