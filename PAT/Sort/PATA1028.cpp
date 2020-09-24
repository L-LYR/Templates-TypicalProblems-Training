#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct student
{
    int id;
    string name;
    int score;
};
const int maxn = 1e5 + 5;
student stu[maxn];

int main(void)
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> stu[i].id >> stu[i].name >> stu[i].score;
    if (c == 1)
        sort(stu, stu + n, [](const student &l, const student &r) -> bool {
            return l.id < r.id;
        });
    else if (c == 2)
        sort(stu, stu + n, [](const student &l, const student &r) -> bool {
            return l.name <= r.name;
        });
    else if (c == 3)
        sort(stu, stu + n, [](const student &l, const student &r) -> bool {
            return l.score <= r.score;
        });

    for (int i = 0; i < n; ++i)
    {
        cout << setfill('0') << setw(6) << stu[i].id << " "
             << stu[i].name << " "
             << stu[i].score << endl;
    }
    return 0;
}