#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 50;
int x[maxn];
int transfer(int64_t sum, int64_t D)
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
    int64_t A, B, D;
    while (cin >> D >> A >> B && D != 0)
    {
        int64_t sum = A + B;
        int len = transfer(sum, D);
        for (int i = 0; i < len; ++i)
            cout << x[i];
        cout << endl;
    }
    return 0;
}
