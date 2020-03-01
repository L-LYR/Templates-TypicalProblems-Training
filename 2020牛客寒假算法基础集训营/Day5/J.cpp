#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi = 3.1415926;
int main(void)
{
    int r, n, i, j;
    scanf("%d%d", &n, &r);
    scanf("%d%d", &i, &j);
    int i_j = abs(i - j);
    double theta = pi / (double)n;
    double len = 2 * sin(theta) * r;
    double ans = len * min(i_j, n - i_j);
    printf("%0.8lf\n", ans);
    return 0;
}