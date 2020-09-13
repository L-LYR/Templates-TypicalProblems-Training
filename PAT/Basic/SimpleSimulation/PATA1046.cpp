#include <iostream>
using namespace std;
const int maxn = 100005;
int D[maxn];

int main(void)
{
    int N, M, qa, qb;
    cin >> N;
    for (int i = 2; i <= N; ++i)
    {
        cin >> D[i];
        D[i] += D[i - 1];
    }
    int sum;
    cin >> sum;
    sum += D[N];
    cin >> M;
    while (--M >= 0)
    {
        cin >> qa >> qb;
        if (qa > qb)
            swap(qa, qb);
        int Dr = D[qb] - D[qa];
        cout << min(Dr, sum - Dr) << endl;
    }
    return 0;
}