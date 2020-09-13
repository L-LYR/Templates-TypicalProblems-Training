#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str;
    char ch;
    while (getline(cin, str))
    {
        ch = getchar();
        auto n = str.find(ch);
        while (n != string::npos)
        {
            str.erase(n, 1);
            n = str.find(ch, n);
        }
        cout << str << endl;
        getchar();
    }
    return 0;
}