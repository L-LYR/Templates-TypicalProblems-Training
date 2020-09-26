#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> ks, cs;

void callatz(int n)
{
    if (cs.count(n) == 1) // if covered, no need to calculate once more
        return;
    else if (ks.count(n) == 1) // if it was a key number, here it is covered
    {
        ks.erase(n);
        cs.insert(n);
        return;
    }
    else
        cs.insert(n); // though it has not appeared, it is covered now.

    if (n == 1)
        return;
    if (n % 2)
        callatz((3 * n + 1) / 2);
    else
        callatz(n / 2);
}

int main(void)
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        if (cs.count(k) == 1)
            continue;
        else
        {
            if (k % 2) // except itself
                callatz((3 * k + 1) / 2);
            else
                callatz(k / 2);
            ks.insert(k);
        }
    }
    auto it = ks.rbegin(); // from big to small
    while (it != ks.rend())
    {
        if (it != ks.rbegin())
            cout << " ";
        cout << *it;
        it++;
    }
    cout << endl;
    return 0;
}