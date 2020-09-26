#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;

struct rec // record
{
    int i;       // index of id
    int t;       // time
    bool status; // whether this record was abandoned
    bool in;     // in or out ?
};

int du[maxn];                  // duration
string cid[maxn];              // car id
unordered_map<string, int> cl; // car id-index
int top;                       // top
vector<rec> recs;              // records

int main(void)
{
    int n, k;
    cin >> n >> k;
    int h, m, s, t;
    string id, type;
    for (int i = 0; i < n; ++i)
    {
        cin >> id;
        if (cl.count(id) == 0)
        {
            cl[id] = top;
            cid[top++] = id;
        }
        cin >> h;
        cin.ignore() >> m;
        cin.ignore() >> s;
        t = h * 3600 + m * 60 + s;
        cin >> type;

        recs.push_back({cl[id], t, false, type == "in"});
    }
    sort(recs.begin(), recs.end(), [](const rec &l, const rec &r) -> bool {
        if (l.i == r.i)
            return l.t < r.t;
        else
            return l.i < r.i;
    }); // sort by id and time

    for (int i = 0; i < n - 1; i++)
    {
        if (recs[i].i == recs[i + 1].i && recs[i].in == true && recs[i + 1].in == false)
        {
            recs[i].status = recs[i + 1].status = true; // valid record
            du[recs[i].i] += recs[i + 1].t - recs[i].t; // add duration
        }
    }

    sort(recs.begin(), recs.end(), [](const rec &l, const rec &r) -> bool {
        if (l.status == r.status)
        {
            if (l.t != r.t)
                return l.t < r.t;
            else
                return l.i < r.i;
        }
        else
            return l.status > r.status;
    }); // sort by status and time and id

    int j = 0, sum = 0; // query is ascending in time
    for (int i = 0; i < k; ++i)
    {
        cin >> h;
        cin.ignore() >> m;
        cin.ignore() >> s;
        t = h * 3600 + m * 60 + s;
        while (recs[j].status && t >= recs[j].t)
        {
            if (recs[j].in)
                sum++;
            else
                sum--;
            j++;
        }
        cout << sum << endl;
    }

    int maxt = 0;
    for (int i = 0; i < top; ++i)
        maxt = max(du[i], maxt);

    for (int i = 0; i < top; ++i)
        if (du[i] == maxt)
            cout << cid[i] << " ";

    cout << setw(2) << setfill('0') << maxt / 3600 << ":"
         << setw(2) << setfill('0') << maxt % 3600 / 60 << ":"
         << setw(2) << setfill('0') << maxt % 60 << endl;

    return 0;
}