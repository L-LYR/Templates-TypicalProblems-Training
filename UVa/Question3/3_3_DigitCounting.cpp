#include <stdio.h>
#include <string.h>
int main(void)
{
    int arr[10];
    int Times, N;
    scanf("%d", &Times);
    for (int i = 0; i < Times; ++i)
    {
        memset(arr, 0, sizeof(int) * 10);
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
        {
            int t = i;
            while (t != 0)
            {
                ++arr[t % 10];
                t /= 10;
            }
        }
        for (int i = 0; i < 9; ++i)
            printf("%d ", arr[i]);
        printf("%d\n", arr[9]);
    }
    return 0;
}