#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct student
{
    string id;
    int score[4];
    int rank[4];
    int type;
    int high;
};

char cat[] = "ACME";

student gl[2005]; // grading list

void rank_all(int t, student *begin, student *end, bool (*cmp)(const student &lhs, const student &rhs))
{
    sort(begin, end, cmp);
    student *p = begin;
    int i = 1;
    while (p < end)
    {
        if (i > 1 && p->score[t] == (p - 1)->score[t])
            p->rank[t] = (p - 1)->rank[t];
        else
            p->rank[t] = i;
        p++;
        i++;
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> gl[i].id;
        cin >> gl[i].score[1] >> gl[i].score[2] >> gl[i].score[3];
        gl[i].score[0] =
            (gl[i].score[1] + gl[i].score[2] + gl[i].score[3]) / 3;
    }
    rank_all(0, gl, gl + n, [](const student &lhs, const student &rhs) -> bool {
        return lhs.score[0] > rhs.score[0];
    });
    rank_all(1, gl, gl + n, [](const student &lhs, const student &rhs) -> bool {
        return lhs.score[1] > rhs.score[1];
    });
    rank_all(2, gl, gl + n, [](const student &lhs, const student &rhs) -> bool {
        return lhs.score[2] > rhs.score[2];
    });
    rank_all(3, gl, gl + n, [](const student &lhs, const student &rhs) -> bool {
        return lhs.score[3] > rhs.score[3];
    });

    int k;
    for (int i = 0; i < n; ++i)
    {
        k = *min_element(gl[i].rank, gl[i].rank + 4);
        gl[i].high = k;
        for (int j = 0; j < 4; ++j)
            if (gl[i].rank[j] == k)
            {
                gl[i].type = j;
                break;
            }
    }

    string id;
    for (int i = 0; i < m; ++i)
    {
        cin >> id;
        int j;
        for (j = 0; j < n; ++j)
            if (gl[j].id == id)
            {
                cout << gl[j].high << " " << cat[gl[j].type] << endl;
                break;
            }
        if (j == n)
            cout << "N/A" << endl;
    }
    return 0;
}