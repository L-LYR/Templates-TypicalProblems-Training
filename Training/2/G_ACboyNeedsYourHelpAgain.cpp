#include <queue>
#include <stack>
#include <iostream>
using namespace std;
int main(void)
{
    int N, M, k;
    string mode, cmd;
    cin >> N;
    while (--N >= 0)
    {
        cin >> M >> mode;
        if (mode[2] == 'F')
        {
            queue<int> q;
            while (--M >= 0)
            {
                cin >> cmd;
                if (cmd[0] == 'I')
                {
                    cin >> k;
                    q.push(k);
                }
                else
                {
                    if (q.empty())
                        cout << "None" << endl;
                    else
                    {
                        cout << q.front() << endl;
                        q.pop();
                    }
                }
            }
        }
        else
        {
            stack<int> s;
            while (--M >= 0)
            {
                cin >> cmd;
                if (cmd[0] == 'I')
                {
                    cin >> k;
                    s.push(k);
                }
                else
                {
                    if (s.empty())
                        cout << "None" << endl;
                    else
                    {
                        cout << s.top() << endl;
                        s.pop();
                    }
                }
            }
        }
    }
    return 0;
}