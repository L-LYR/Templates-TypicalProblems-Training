#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int L, M;
    int l, r, sum;
    while (cin >> L >> M && L != 0)
    {
        vector<int> tree(L + 1, 1);
        sum = 0;
        while (--M >= 0)
        {
            cin >> l >> r;
            for (int i = l; i <= r; ++i)
                tree[i] = 0;
        }
        for (int i = 0; i <= L; ++i)
            sum += tree[i];
        cout << sum << endl;
    }
    return 0;
}