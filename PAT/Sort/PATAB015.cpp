#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct user
{
    string id;
    int d;
    int c;
    int tol; // tol = d + c
    int type;
};

user list[100005];

bool cmp(const user &lhs, const user &rhs)
{
    if (lhs.type != rhs.type)
        return lhs.type < rhs.type;
    else if (lhs.tol != rhs.tol)
        return lhs.tol > rhs.tol;
    else if (lhs.d != rhs.d)
        return lhs.d > rhs.d;
    else
        return lhs.id < rhs.id;
}

int main(void)
{
    int n, N, L, H;
    cin >> N >> L >> H;
    n = N;

    user tmp;
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp.id >> tmp.d >> tmp.c;
        tmp.tol = tmp.d + tmp.c;
        if (tmp.d < L || tmp.c < L)
        {
            n--;
            tmp.type = 5;
        }
        else if (tmp.d >= H && tmp.c >= H)
            tmp.type = 1;
        else if (tmp.d >= H && tmp.c < H)
            tmp.type = 2;
        else if (tmp.d < H && tmp.c < H && tmp.d >= tmp.c)
            tmp.type = 3;
        else
            tmp.type = 4;
        list[i] = tmp;
    }
    sort(list, list + N, cmp);
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << list[i].id << " "
             << list[i].d << " "
             << list[i].c << endl;
    }

    return 0;
}