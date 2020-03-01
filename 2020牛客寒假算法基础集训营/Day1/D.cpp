#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005;
bool arr[maxn];
int main(void)
{
    int n, num;
    scanf("%d", &n);
    memset(arr, false, sizeof(arr));
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &num);
        arr[num] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        if (!arr[i])
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}