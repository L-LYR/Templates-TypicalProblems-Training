#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100005;
int segTree[maxn * 4];
int tag[maxn * 4];

#define get_mid(left, right) left + ((right - left) >> 1)

inline int left_son(int parent)
{
    return parent << 1;
}
inline int right_son(int parent)
{
    return parent << 1 | 1;
}
inline void push_up_sum(int parent)
{
    segTree[parent] = segTree[left_son(parent)] + segTree[right_son(parent)];
}

inline void modify(int parent, int left, int right, int delta)
{
    tag[parent] += delta;
    segTree[parent] += (right - left + 1) * delta;
}

inline void push_down(int parent, int left, int right)
{
    int mid = get_mid(left, right);
    modify(left_son(parent), left, mid, tag[parent]);
    modify(right_son(parent), mid + 1, right, tag[parent]);
    tag[parent] = 0;
}

void update(int interval_left, int interval_right, int parent, int left, int right, int delta)
{
    if (left >= interval_left && right <= interval_right)
    {
        modify(parent, right, left, delta);
        return;
    }

    push_down(parent, left, right);
    int mid = get_mid(left, right);

    if (interval_left <= mid)
        update(interval_left, interval_right,
               left_son(parent), left, mid, delta);
    if (interval_right > mid)
        update(interval_left, interval_right,
               right_son(parent), mid + 1, right, delta);

    push_up_sum(parent);
}

int query(int qleft, int qright, int parent, int left, int right)
{
    int ans = 0;
    if (qleft <= left && right <= qright)
        return segTree[parent];

    push_down(parent, left, right);
    int mid = get_mid(left, right);

    if (qleft <= mid)
        ans += query(qleft, qright, left_son(parent), left, mid);

    if (qright > mid)
        ans += query(qleft, qright, right_son(parent), mid + 1, right);
    return ans;
}

int main(void)
{
    int n;
    while (cin >> n && n != 0)
    {
        int a, b;

        memset(segTree, 0, sizeof(segTree));
        memset(tag, 0, sizeof(tag));

        for (int k = 0; k < n; ++k)
        {
            cin >> a >> b;
            update(a, b, 1, 1, n, 1);
        }

        cout << query(1, 1, 1, 1, n);
        for (int i = 2; i <= n; ++i)
            cout << " " << query(i, i, 1, 1, n);
        cout << endl;
    }
    return 0;
}