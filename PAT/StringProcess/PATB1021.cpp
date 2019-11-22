#include <iostream>
#include <map>
using namespace std;
map<char, int> dic;
int main(void)
{
    char ch;
    while ((ch = getchar()) && ch != '\n')
        dic[ch]++;
    for (auto i : dic)
        cout << i.first << ":" << i.second << endl;
    return 0;
}