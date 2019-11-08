#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 20;
inline double dis(const pair<double, double> &a, const pair<double, double> &b)
{
    return sqrt(pow(fabs(a.first - b.first), 2) + pow(fabs(a.second - b.second), 2));
}
vector<pair<double, double>> p;
bool visited[maxn];
double ans = INT32_MAX, curd = 0;
int n;
void dfs(pair<double, double> cur, int depth)
{
    if (curd > ans)
        return;
    if (depth == n)
        ans = min(ans, curd);
    else
    {
        for (int i = 1; i < p.size(); ++i)
        {
            if (!visited[i])
            {
                double tmp = dis(p[i], cur);
                visited[i] = true;
                curd += tmp;
                dfs(p[i], depth + 1);
                visited[i] = false;
                curd -= tmp;
            }
        }
    }
}

int main(void)
{
    double x, y;
    cin >> n;
    p.push_back({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        p.push_back({x, y});
    }
    dfs({0, 0}, 0);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}