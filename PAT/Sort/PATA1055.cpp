#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
struct person
{
    string n;
    int a;
    int w;
};
person p[maxn];
int age_cnt[205];

int main(void)
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> p[i].n >> p[i].a >> p[i].w;
    sort(p, p + N, [](const person &l, const person &r) -> bool {
        if (l.w != r.w)
            return l.w >= r.w;
        else if (l.a != r.a)
            return l.a < r.a;
        else
            return l.n < r.n;
    });

    // N <= 1e5; M <= 100
    // 1e5 >> 100
    // So choose the first 100 people having the same age.

    vector<person> tp;
    for (int i = 0; i < N; ++i)
    {
        if (age_cnt[p[i].a] <= 100)
        {
            tp.push_back(p[i]);
            age_cnt[p[i].a]++;
        }
    }

    int l, r, m;
    for (int i = 1; i <= K; ++i)
    {
        cin >> m >> l >> r;
        cout << "Case #" << i << ":" << endl;
        bool flag = true;
        for (int j = 0; j < tp.size(); ++j)
        {
            if (tp[j].a >= l && tp[j].a <= r && m > 0)
            {
                flag = false;
                m--;
                cout << tp[j].n << " "
                     << tp[j].a << " "
                     << tp[j].w << endl;
            }
        }
        if (flag)
            cout << "None" << endl;
    }
    return 0;
}