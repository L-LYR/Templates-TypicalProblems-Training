#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    int a, b;
    string n;
    while (cin >> a >> n >> b)
    {
        int i = 0;
        long ans = 0;
        do
        {
            ans *= a;
            if (isdigit(n[i]))
                ans += n[i] - '0';
            else if (isupper(n[i]))
                ans += n[i] - 'A' + 10;
            else
                ans += n[i] - 'a' + 10;
            ++i;
        } while (i < n.length());

        n.clear();
        do
        {
            i = ans % b;
            ans /= b;
            if (i < 10)
                n.append(to_string(i));
            else
                n.append(1, (char)('A' + i - 10));
        } while (ans > 0);
        reverse(n.begin(), n.end());
        cout << n << endl;

        n.clear();
    }
    return 0;
}