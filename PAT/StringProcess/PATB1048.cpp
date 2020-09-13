#include <cstring>
#include <iostream>

using namespace std;

char bind[14] = "0123456789JQK";
int main(void)
{
    string A, B;
    cin >> A >> B;
    if (A.length() > B.length())
        B.insert(0, A.length() - B.length(), '0');

    int o = -1, a, b, i = A.length() - 1, j = B.length() - 1;
    while (i >= 0)
    {
        a = A[i] - '0';
        b = B[j] - '0';
        if (o)
            B[j] = bind[(a + b) % 13];
        else
        {
            if (b - a < 0)
                B[j] = b - a + 10 + '0';
            else
                B[j] = b - a + '0';
        }
        o = ~o;
        i--;
        j--;
    }

    cout << B << endl;

    return 0;
}