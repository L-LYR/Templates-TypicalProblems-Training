#include <stack>
#include <string>
#include <iostream>
using namespace std;
int main(void)
{
    string gift;
    while (cin >> gift)
    {
        int len = gift.length(), cnt = 0;
        stack<char> cs;
        for (int i = 0; i < len; ++i)
        {
            if (gift[i] == '(')
            {
                cs.push('(');
                cnt++;
            }
            else if (gift[i] == ')')
            {
                cs.pop();
                cnt--;
            }
            else
            {
                cout << cnt << endl;
                break;
            }
        }
    }
    return 0;
}