#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <vector>

using namespace std;

map<set<int>, int> set_ID;
vector<set<int>> ID_set;
stack<int> s;

int get_ID(set<int> new_set)
{
    if (set_ID.find(new_set) != set_ID.end())
        return set_ID[new_set];
    ID_set.push_back(new_set);
    return set_ID[new_set] = set_ID.size();
}

int main(void)
{
    ofstream file("output.txt", ios::out);
    streambuf *backup = cout.rdbuf();
    cout.rdbuf(file.rdbuf());

    int T, N;
    int ID;
    string cmd;

    cin >> T;
    while (T-- > 0)
    {
        cin >> N;
        ID = 0;
        while (N-- > 0)
        {
            cin >> cmd;
            switch (cmd[0])
            {
            case 'P':
                s.push(get_ID(set<int>()));
                break;
            case 'D':
                s.push(s.top());
                break;
            default:
                set<int> set1 = ID_set[s.top()];
                s.pop();
                set<int> set2 = ID_set[s.top()];
                s.pop();
                set<int> target;
                switch (cmd[0])
                {
                case 'U':
                    set_union(set1.begin(), set1.end(),
                              set2.begin(), set2.end(),
                              inserter(target, target.begin()));
                    break;
                case 'I':
                    set_intersection(set1.begin(), set1.end(),
                                     set2.begin(), set2.end(),
                                     inserter(target, target.begin()));
                    break;
                case 'A':
                    set2.insert(get_ID(set1));
                    target = set2;
                    break;
                }
                s.push(get_ID(target));
            }
            cout << ID_set[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    cout.rdbuf(backup);
    file.close();
    return 0;
}