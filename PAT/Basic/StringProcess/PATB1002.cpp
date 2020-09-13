#include <iostream>
#include <string>
using namespace std;
string dic[] = {"ling", "yi", "er", "san", "si",
                "wu", "liu", "qi", "ba", "jiu"};
int main(void)
{
    char ch;
    int ans = 0;
    while ((ch = getchar()) != '\n')
        ans += ch - '0';
    if (ans >= 100)
        cout << dic[ans / 100] << " "
             << dic[ans % 100 / 10] << " "
             << dic[ans % 10] << endl;
    else if (ans >= 10)
        cout << dic[ans / 10] << " "
             << dic[ans % 10] << endl;
    else
        cout << dic[ans] << endl;

    return 0;
}