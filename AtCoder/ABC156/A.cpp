#include <iostream>

using namespace std;

int main(void)
{
    int n, dr, ir;
    scanf("%d%d", &n, &dr);
    if (n >= 10)
        ir = dr;
    else
        ir = dr + 100 * (10 - n);
    printf("%d\n", ir);
    return 0;
}