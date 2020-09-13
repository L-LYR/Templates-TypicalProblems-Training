#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 33;
int x[maxn];

int transfer(int n, int b)
{
    int i = 0;
    do
    {
        x[i++] = n % b;
        n /= b;
    } while (n != 0);
    return i;
}

int main(void)
{
    int n, b;
    cin >> n >> b;
    int len = transfer(n, b), flag = 1;
    reverse(x, x + len);

    for (int i = 0, j = len - 1; i < j; ++i, --j)
    {
        if (x[i] != x[j])
        {
            flag = 0;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    cout << x[0];
    for (int i = 1; i < len; ++i)
        cout << " " << x[i];
    cout << endl;
    return 0;
}