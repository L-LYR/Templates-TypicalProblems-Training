#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int maxn = 4e4 + 5;
const int maxm = 105;
const int maxk = 7;

struct student
{
    int id;         // id
    int ge, gi, fi; // G_e G_i Final
    int want[maxk]; // college preference
    int s;          // school
    friend bool operator==(const student &l, const student &r)
    {
        return l.fi == r.fi && l.ge == r.ge;
    }
    friend bool operator<(const student &l, const student &r)
    {
        if (l.fi != r.fi)
            return l.fi > r.fi;
        else if (l.ge != r.ge)
            return l.ge > r.ge;
        else
            return l.id < r.id;
    }
};

student st[maxn];
int quota[maxm];
priority_queue<int, vector<int>, greater<int>> actual[maxm];

int main(void)
{
    // input
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
        cin >> quota[i];
    for (int i = 0; i < n; ++i)
    {
        st[i].id = i;
        cin >> st[i].ge >> st[i].gi;
        st[i].fi = st[i].ge + st[i].gi;
        for (int j = 0; j < k; ++j)
            cin >> st[i].want[j];
    }
    // sort in decent order
    sort(st, st + n);
    int w;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            w = st[i].want[j];
            if (quota[w] > 0)
            {
                quota[w]--;
                actual[w].push(st[i].id);
                st[i].s = w;
                break;
            }
            else if ((i > 0 && st[i] == st[i - 1] && st[i - 1].s == w))
            {
                actual[w].push(st[i].id);
                st[i].s = w;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; !actual[i].empty(); ++j)
        {
            if (j > 0)
                cout << " ";
            cout << actual[i].top();
            actual[i].pop();
        }
        cout << endl;
    }

    return 0;
}