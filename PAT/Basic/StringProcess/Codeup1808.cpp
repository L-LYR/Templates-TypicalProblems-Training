#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(void)
{
    const int maxn = 10005;
    char in[maxn];
    string target, ans, b;

    cin >> target;
    int len = target.length();
    for (int i = 0; i < len; ++i)
        target[i] = tolower(target[i]);

    char *p = in;
    getchar();
    while ((*p = getchar()) != EOF)
    {
        if (isalpha(*p))
            b += tolower(*p);
        else
            b += *p;
        ++p;
    }
    *p = '\0';
    ans = in;
    size_t n = b.find(target);
    while (n != string::npos)
    {
        ans.erase(n, len);
        b.erase(n, len);
        n = b.find(target);
    }
    n = ans.find(' ');
    while (n != string::npos)
    {
        ans.erase(n, 1);
        n = ans.find(' ');
    }
    cout << ans << endl;
    return 0;
}