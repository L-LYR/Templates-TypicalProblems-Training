#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct student
{
    string name;
    string id;
    int grade;
    friend bool operator<(const student &l, const student &r)
    {
        return l.grade < r.grade;
    }
};

int main(void)
{
    vector<student> sv;
    int n;
    cin >> n;
    student ts;

    for (int i = 0; i < n; ++i)
    {
        cin >> ts.name >> ts.id >> ts.grade;
        sv.push_back(ts);
    }
    int l, r;
    cin >> l >> r;
    priority_queue<student> ans;
    for (auto i : sv)
    {
        if (i.grade <= r && i.grade >= l)
            ans.push(i);
    }

    if (ans.empty())
    {
        cout << "NONE" << endl;
        return 0;
    }

    while (!ans.empty())
    {
        ts = ans.top();
        ans.pop();
        cout << ts.name << " "
             << ts.id << endl;
    }

    return 0;
}