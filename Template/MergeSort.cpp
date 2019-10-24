// merge_sort can used to calculate inversion pairs.
// Luogu P1908
#include <cstdio>

inline int read(void)
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48); //pay attention to this
        ch = getchar();
    }
    return x * f;
}

const int maxn = 500005;
int a[maxn], t[maxn], n;
long long ans = 0;

void mergeSort(int l, int h)
{
    if (l == h)
        return;
    int mid = l + ((h - l) >> 1);

    mergeSort(l, mid);
    mergeSort(mid + 1, h);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else
        {
            t[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
        t[k++] = a[i++];
    while (j <= h)
        t[k++] = a[j++];
    for (i = l; i <= h; ++i)
        a[i] = t[i];
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    mergeSort(1, n);
    printf("%lld", ans);
    // for (int i = 1; i <= n; ++i)
    // printf("%d ", a[i]);
    return 0;
}