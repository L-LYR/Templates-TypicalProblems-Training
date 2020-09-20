#include <algorithm>
#include <iostream>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int j = 0, last = -1;
    for (int i = 0; i < n; ++i)
    {
        if(last!=a[i])
            j = 0;
        if (a[i] == b[i])
        {
            for (; j < n; ++j)
            {
                if (a[j] != a[i] && b[j] != a[i])
                {
                    swap(b[i], b[j]);
                    break;
                }
            }
            if (a[i] == b[i])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        last = a[i];
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}