#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string flag(c < 0 ? "-" : "");
    c = abs(c);
    if (c < 100)
    {
        cout << flag << c << endl;
        return 0;
    }

    string ans;
    while (c >= 100)
    {
        // string inc = to_string(c % 1000);
        // while (inc.length() < 3) {
        //     inc = "0" + inc;
        // }
        char inc[5];
        sprintf(inc, "%03d", c % 1000);
        string tmp(inc);

        if (ans != "")
            ans = "," + ans;

        ans = tmp + ans;
        c /= 1000;
    }
    if (c != 0)
        ans = to_string(c) + "," + ans;
    cout << flag << ans << endl;
    return 0;
}