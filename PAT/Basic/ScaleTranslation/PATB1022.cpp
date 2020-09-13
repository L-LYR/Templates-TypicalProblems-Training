#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 32;
int x[maxn];
int transfer(int sum, int D)
{
    int i = 0;
    do
    {
        x[i++] = sum % D;
        sum /= D;
    } while (sum > 0);
    reverse(x, x + i);
    return i;
}

int main(void)
{
    int A, B, D;
    cin >> A >> B >> D;
    int sum = A + B;
    int len = transfer(sum, D);
    for (int i = 0; i < len; ++i)
        cout << x[i];
    return 0;
}
