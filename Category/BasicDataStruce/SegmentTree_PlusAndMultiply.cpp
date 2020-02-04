#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

long long arr[MAXN];
long long segTree[MAXN * 4];
long long mulTag[MAXN * 4] = {1}; //have a higher priority
long long addTag[MAXN * 4];

int p = 1;

inline int left_son(int parent) { return parent << 1; }
inline int right_son(int parent) { return (parent << 1) | 1; }
inline void push_up_sum(int parent) { segTree[parent] = segTree[left_son(parent)] + segTree[right_son(parent)]; }

void build(int parent, int left, int right)
{
    if (left == right)
    {
        segTree[left] = arr[left];

        return;
    }

    int mid = left + ((right - left) >> 1);
    build(left_son(parent), left, mid);
    build(right_son(parent), mid + 1, right);
    push_up_sum(parent);
}

inline void modify_cur(int parent, int intervalLen, long long mul, long long add)
{
    mulTag[parent] = (mulTag[parent] * mul) % p;
    addTag[parent] = (addTag[parent] * mul + add) % p;

    segTree[parent] = (mul * segTree[parent] + add * intervalLen) % p;
}

inline void push_down(int parent, int left, int right)
{
    int mid = left + ((right - left) >> 1);
    modify_cur(left_son(parent), mid - left + 1, mulTag[parent], addTag[parent]);
    modify_cur(right_son(parent), right - mid, mulTag[parent], addTag[parent]);
    addTag[parent] = 0;
    mulTag[parent] = 1;
}

void mulUpdate(int interval_left, int interval_right, int parent, int left, int right, int mul)
{
    if (left >= interval_left && right <= interval_right)
    {
        segTree[parent] = (segTree[parent] * mul) % p;
        mulTag[parent] = (mulTag[parent] * mul) % p;
        addTag[parent] = (addTag[parent] * mul) % p;
        return;
    }
    push_down(parent, left, right);
    int mid = left + ((right - left) >> 1);
    if (mid >= interval_left)
        mulUpdate(interval_left, interval_right,
                  left_son(parent), left, mid, mul);
    if (mid < interval_right)
        mulUpdate(interval_left, interval_right,
                  right_son(parent), mid + 1, right, mul);
    push_up_sum(parent);
}

void addUpdate(int interval_left, int interval_right, int parent, int left, int right, long long add)
{
    if (left >= interval_left && right <= interval_right)
    {
        addTag[parent] = (addTag[parent] + add) % p;
        segTree[parent] = (segTree[parent] + (right - left + 1) * add) % p;
        return;
    }
    push_down(parent, left, right);

    int mid = left + ((right - left) >> 1);

    if (interval_left <= mid)
        addUpdate(interval_left, interval_right,
                  left_son(parent), left, mid, add);

    if (interval_right > mid)
        addUpdate(interval_left, interval_right,
                  right_son(parent), mid + 1, right, add);

    push_up_sum(parent);
}

long long query(int qLeft, int qRight, int parent, int left, int right)
{
    long long res = 0;

    if (qLeft <= left && right <= qRight)
        return segTree[parent];

    push_down(parent, left, right);

    int mid = left + ((right - left) >> 1);

    if (qLeft <= mid)
        res += query(qLeft, qRight, left_son(parent),
                     left, mid);

    if (qRight > mid)
        res += query(qLeft, qRight, right_son(parent),
                     mid + 1, right);

    return res % p;
}

int main(void)
{
    int N, M, i;
    cin >> N >> M;
    for (i = 1; i <= N; ++i)
        cin >> arr[i];
    build(1, 1, N);
    int opt, x, y;
    long long k;
    for (i = 0; i < M; ++i)
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x >> y >> k;
            mulUpdate(x, y, 1, 1, N, k);
            break;
        case 2:
            cin >> x >> y >> k;
            addUpdate(x, y, 1, 1, N, k);
            break;
        case 3:
            cin >> x >> y;
            cout << query(x, y, 1, 1, N) << endl;
        }
    }
    return 0;
}