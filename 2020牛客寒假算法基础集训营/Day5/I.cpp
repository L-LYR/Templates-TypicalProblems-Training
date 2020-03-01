#include <iostream>
#include <algorithm>
using namespace std;
double q[14];
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, t; i < n; ++i)
    {
        scanf("%d", &t);
        q[i] = (double)t / (double)m;
    }

    double cur = q[('I' - 'A')];
    if (cur >= 0.8)
        printf("Yes\n");
    else
    {
        sort(q, q + n, greater<double>());
        unique(q, q + n);
        if (cur >= q[2])
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}