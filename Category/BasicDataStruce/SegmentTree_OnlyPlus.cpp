#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

long long arr[MAXN];
long long segTree[MAXN * 4];
long long tag[MAXN * 4];

inline int left_son(int parent) { return parent << 1; }
inline int right_son(int parent) { return (parent << 1) | 1; }
inline void push_up_sum(int parent) { segTree[parent] = segTree[left_son(parent)] + segTree[right_son(parent)]; }

// inline void push_up_min(int parent) { segTree[parent] = min(segTree[left_son(parent)], segTree[right_son(parent)]); }
// inline void push_up_max(int parent) { segTree[parent] = max(segTree[left_son(parent)], segTree[right_son(parent)]); }

void build(int parent, int left, int right)
{
    if (left == right)
    {
        segTree[parent] = arr[left];
        return;
    }

    int mid = left + ((right - left) >> 1);
    build(left_son(parent), left, mid);
    build(right_son(parent), mid + 1, right);
    //PushUp
    push_up_sum(parent);
}

inline void modify_cur(int parent, int left, int right, long long delta)
{
    tag[parent] += delta;
    segTree[parent] += (right - left + 1) * delta;
}

inline void push_down(int parent, int left, int right)
{
    int mid = left + ((right - left) >> 1);
    modify_cur(left_son(parent), left, mid, tag[parent]);
    modify_cur(right_son(parent), mid + 1, right, tag[parent]);
    tag[parent] = 0;
}

void update(int interval_left, int interval_right, int parent, int left, int right, long long delta)
{
    if (left >= interval_left && right <= interval_right)
    {
        tag[parent] += delta;
        segTree[parent] += (right - left + 1) * delta;
        return;
    }
    push_down(parent, left, right);

    int mid = left + ((right - left) >> 1);

    if (interval_left <= mid)
        update(interval_left, interval_right,
               left_son(parent), left, mid, delta);

    if (interval_right > mid)
        update(interval_left, interval_right,
               right_son(parent), mid + 1, right, delta);

    push_up_sum(parent);
}

long long query(int qLeft, int qRight, int parent, int left, int right)
{
    long long res = 0;
    
    if (qLeft <= left && right <= qRight)
        return segTree[parent];
        
    int mid = left + ((right - left) >> 1);
    push_down(parent, left, right);

    if (qLeft <= mid)
        res += query(qLeft, qRight, left_son(parent),
                     left, mid);

    if (qRight > mid)
        res += query(qLeft, qRight, right_son(parent),
                     mid + 1, right);

    return res;
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
            update(x, y, 1, 1, N, k);
            break;
        case 2:
            cin >> x >> y;
            cout << query(x, y, 1, 1, N) << endl;
        }
    }
    return 0;
}