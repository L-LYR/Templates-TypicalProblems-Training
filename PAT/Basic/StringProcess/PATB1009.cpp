#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    char str[90][90];
    int i = 0;
    while (scanf("%s", str[i]) != EOF)
        ++i;
    --i;
    while (i)
        cout << str[i--] << " ";
    cout << str[i] << endl;
    return 0;
}