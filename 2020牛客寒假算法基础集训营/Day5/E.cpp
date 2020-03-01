#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

int main(void)
{
    ll n;
    scanf("%lld", &n);

    if ((n & (n - 1)) == 0)
        printf("Alice\n");
    else
        printf("Bob\n");

    return 0;
}