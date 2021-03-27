#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 2e7 + 5;
int a[maxn], num[maxn];
int main(void)
{
    int n;
    scanf("%d", &n);
    int size = 0;
    memset(a, -1, sizeof(a));
    for (int i = 1, tmp; i <= n; ++i)
    {
        scanf("%d", &tmp);
        a[i] = tmp;
        if (tmp != -1)
            size++;
        num[tmp] = i;
    }
    printf("The size of the tree is %d\n", size);
    printf("Node %d is the root node of the tree\n", a[1]);
    for (int i = 1; i <= size; ++i)
    {
        printf("The father of node %d is %d, "
               "the left child is %d, "
               "and the right child is %d\n",
               i, a[num[i] / 2], a[num[i] * 2], a[num[i] * 2 + 1]);
    }
    return 0;
}