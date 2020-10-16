#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    long double ans = 0.0, a;
    for (int i = 0; i < n; ++i) {
        scanf("%llf", &a);
        ans += a * (i + 1) * (n - i);
    }
    printf("%.2llf\n", ans);
    return 0;
}