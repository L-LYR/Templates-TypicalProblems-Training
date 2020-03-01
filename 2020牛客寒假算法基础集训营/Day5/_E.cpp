#include <iostream>
#include <cstring>
using namespace std;
bool f(int cur, int k)
{
    bool ret = true;
    for (int i = 1; i <= min(cur, k); ++i)
        ret = ret && f(cur - i, i);
    return !ret;
}

int main(void)
{
    for (int i = 2; i <= 100; ++i)
        printf("%d %d\n", i, f(i, i - 1));

    return 0;
}