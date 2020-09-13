#include <iostream>
#include <cstring>
using namespace std;

bool solve(char *p, char *q)
{
    while (p < q)
        if (*p++ != *q--)
            return false;
    return true;
}

int main(void)
{
    char str[260];
    cin.getline(str, 255);
    char *p = str, *q = str + strlen(str) - 1;
    cout << (solve(p, q) ? "YES" : "NO") << endl;
    return 0;
}