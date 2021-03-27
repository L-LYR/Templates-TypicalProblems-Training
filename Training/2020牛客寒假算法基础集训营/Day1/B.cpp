#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, x, a, b;
    scanf("%d %d %d %d", &n, &x, &a, &b);
    double p = 0.01 * x;
    double e = n * (p * a + (1 - p) * b);
    printf("%0.2lf\n", e);

    return 0;
}