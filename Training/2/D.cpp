#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;
int main(void)
{
    string str;
    stack<double> vals;
    stack<char> ops;
    while (getline(cin, str) && str != "0")
    {
        str += " ";
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            double x = 0;
            while (isdigit(str[i]))
            {
                x = x * 10 + str[i] - '0';
                ++i;
            }
            vals.push(x);
            switch (str[++i])
            {
            case '+':
            case '-':
                while (!ops.empty())
                {
                    double x1 = vals.top();
                    vals.pop();
                    switch (ops.top())
                    {
                    case '+':
                        vals.top() += x1;
                        break;
                    case '-':
                        vals.top() -= x1;
                        break;
                    case '/':
                        vals.top() /= x1;
                        break;
                    case '*':
                        vals.top() *= x1;
                        break;
                    }
                    ops.pop();
                }
                ops.push(str[i++]);
                break;
            case '*':
            case '/':
                while (!ops.empty() && (ops.top() == '/' || ops.top() == '*'))
                {
                    double x1 = vals.top();
                    vals.pop();
                    if (ops.top() == '*')
                        vals.top() *= x1;
                    else
                        vals.top() /= x1;
                    ops.pop();
                }
                ops.push(str[i++]);
                break;
            default:
                break;
            }
        }
        while (!ops.empty())
        {
            double x1 = vals.top();
            vals.pop();
            switch (ops.top())
            {
            case '+':
                vals.top() += x1;
                break;
            case '-':
                vals.top() -= x1;
                break;
            case '/':
                vals.top() /= x1;
                break;
            case '*':
                vals.top() *= x1;
                break;
            }
            ops.pop();
        }
        printf("%.2f\n", vals.top());
        // cout << fixed << setprecision(2) << vals.top() << endl;
        vals.pop();
    }
    return 0;
}