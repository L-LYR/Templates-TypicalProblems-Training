#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    stack<char> s;
    char c;
    while (cin >> c)
    {
        if (c == ']' && !s.empty() && s.top() == '[')
        {
            s.pop();
            continue;
        }
        else if (c == '}' && !s.empty() && s.top() == '{')
        {
            s.pop();
            continue;
        }
        else if (c == ')' && !s.empty() && s.top() == '(')
        {
            s.pop();
            continue;
        }
        s.push(c);
    }
    if (s.empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}