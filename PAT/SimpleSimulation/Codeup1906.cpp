#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int ans;
    string a, b;
    while (cin >> a)
    {
        cin >> b;
        ans = 0;
        for (int i = 0; i < a.length(); ++i)
            for (int j = 0; j < b.length(); ++j)
                ans += (a[i] - '0') * (b[j] - '0');
        cout << ans << endl;
    }
    return 0;
}