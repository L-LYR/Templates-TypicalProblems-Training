#include <iostream>
#include <time.h>
#include <cstdio>
// It is said that getchar() is faster than scanf().
inline long long read(void)
{
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
using namespace std;
int main(void)
{
    long long a;

    clock_t begin = clock();
    cin >> a;
    clock_t end = clock();
    cout << (end - begin) << endl;
    cout << a << endl;

    begin = clock();
    scanf("%lld", &a);
    end = clock();
    cout << (end - begin) << endl;
    cout << a << endl;

    begin = clock();
    a = read();
    end = clock();
    cout << (end - begin) << endl;
    cout << a << endl;

    ios::sync_with_stdio(false);
    cin.tie(0);
    begin = clock();
    cin >> a;
    end = clock();
    cout << (end - begin) << endl;
    cout << a << endl;

    return 0;
}