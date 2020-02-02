#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 2010;
int n, nums[maxn];

int main(void)
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }

    int flag = 1;
    int id = 1;

    queue<int> q;
    q.push(id);
    nums[1]++;

    while (!q.empty() && flag)
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i < nums[cur]; ++i)
        {
            id++;
            if (id > n)
            {
                flag = 0;
                break;
            }
            q.push(id);
        }
    }

    if (flag && id == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}