#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
const int maxk = 6;

struct user
{
    int id;
    int tol;
    int pa[maxk];
    int solved;
    bool sub;
};

int slim[maxk];

user u[maxn];

int main(void)
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; ++i)
        cin >> slim[i];
    for (int i = 1; i <= n; ++i)
    {
        u[i].id = i;
        u[i].tol = 0;
        memset(u[i].pa, -1, sizeof(int) * maxk);
        u[i].solved = 0;
        u[i].sub = false;
    }

    int tid, tk, ts;
    for (int i = 0; i < m; ++i)
    {
        cin >> tid >> tk >> ts;
        if (ts == -1)
            ts = 0;
        else
            u[tid].sub = true;
        if (ts > u[tid].pa[tk])
        {
            if (ts == slim[tk])
                u[tid].solved++;
            if (u[tid].pa[tk] == -1)
                u[tid].tol += ts;
            else
                u[tid].tol += ts - u[tid].pa[tk];
            u[tid].pa[tk] = ts;
        }
    }

    sort(u + 1, u + n + 1, [](const user &l, const user &r) -> bool {
        if (l.tol != r.tol)
            return l.tol > r.tol;
        else if (l.solved != r.solved)
            return l.solved > r.solved;
        else
            return l.id < r.id;
    });

    int r = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (u[i].sub == false)
            break;
        if (i > 1 && u[i].tol != u[i - 1].tol)
            r = i;
        cout << r << " ";
        cout << setw(5) << setfill('0') << u[i].id << " "
             << u[i].tol << " ";
        for (int j = 1; j <= k; ++j)
        {
            if (j - 1 != 0)
                cout << " ";
            if (u[i].pa[j] == -1)
                cout << "-";
            else
                cout << u[i].pa[j];
        }
        cout << endl;
    }
    return 0;
}