#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string ans, exp;
    getline(cin, ans, 'E');
    getline(cin, exp);
    char s = ans[0];
    ans.erase(0, 1);
    ans.erase(1, 1);
    int e = atoi(exp.c_str());

    if (e < 0)
    {
        e = -e;
        ans.insert(0, e - 1, '0');
        ans.insert(0, "0.");
    }
    else
    {
        if (e + 1 > ans.length())
            ans.insert(ans.length(), e + 1 - ans.length(), '0');
        if (e + 1 < ans.length())
            ans.insert(e + 1, 1, '.');
    }
    if (s == '-')
        ans.insert(0, 1, s);
    cout << ans << endl;
    return 0;
}