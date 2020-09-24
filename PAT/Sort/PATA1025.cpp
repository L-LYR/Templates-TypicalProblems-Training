#include <algorithm>
#include <iostream>
using namespace std;

struct user
{
    string id;
    int score;
    int f_rank;
    int num;
    int l_rank;
};

user list[30005];
int top = 0;

bool cmp(const user &lhs, const user &rhs)
{
    if (lhs.score > rhs.score)
        return true;
    else if (lhs.score < rhs.score)
        return false;
    else
        return lhs.id < rhs.id;
}

int main(void)
{
    int n, m;
    cin >> n;
    for (int j = 1; j <= n; ++j)
    {
        cin >> m;
        int last = top;
        for (int i = 0; i < m; ++i)
        {
            cin >> list[top].id >> list[top].score;
            list[top].num = j;
            top++;
        }
        sort(list + last, list + top, cmp);
        for (int i = last; i < top; ++i)
        {
            if (i > last && list[i].score == list[i - 1].score)
                list[i].l_rank = list[i - 1].l_rank;
            else
                list[i].l_rank = i - last + 1;
            // cout << list[i].id << " " << list[i].score << " " << endl;
        }
        // cout << endl;
    }
    sort(list, list + top, cmp);
    cout << top << endl;
    for (int i = 0; i < top; ++i)
    {
        if (i > 0 && list[i].score == list[i - 1].score)
            list[i].f_rank = list[i - 1].f_rank;
        else
            list[i].f_rank = i + 1;
        cout << list[i].id << " "
             << list[i].f_rank << " "
             << list[i].num << " "
             << list[i].l_rank << endl;
    }

    return 0;
}