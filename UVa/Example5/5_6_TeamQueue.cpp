#include <iostream>
// #include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <map>
const int MAX = 1100;

using namespace std;

int main(void)
{

    // ofstream file("output.txt", ios::out);
    // streambuf *backup = cout.rdbuf();
    // cout.rdbuf(file.rdbuf());

    int t;
    int num, ID, count = 1;
    string cmd;
    while (cin >> t && t != 0)
    {
        map<int, int> IDmap;
        queue<int> teamq;
        queue<int> q[MAX];

        cout << "Scenario #" << count++ << endl;
        for (int i = 1; i <= t; ++i)
        {
            cin >> num;
            for (int j = 0; j < num; ++j)
            {
                cin >> ID;
                IDmap[ID] = i;
            }
        }

        while (cin >> cmd && cmd[0] != 'S')
        {
            if (cmd[0] == 'E')
            {
                cin >> ID;
                if (q[IDmap[ID]].empty())
                    teamq.push(IDmap[ID]);
                q[IDmap[ID]].push(ID);
            }
            else if (cmd[0] == 'D')
            {
                int head = teamq.front();
                cout << q[head].front() << endl;
                q[head].pop();
                if (q[head].empty())
                    teamq.pop();
            }
        }
        cout << endl;
    }
    // cout.rdbuf(backup);
    // file.close();
    return 0;
}