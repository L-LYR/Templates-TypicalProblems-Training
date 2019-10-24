#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N, Q;
    int q, temp;
    int count = 1;
    while (cin >> N >> Q && N != 0)
    {
        vector<int> num;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            num.push_back(temp);
        }
        sort(num.begin(), num.end());
        cout << "CASE# " << count++ << ":" << endl;
        for (int i = 0; i < Q; ++i)
        {
            cin >> q;
            auto pos = lower_bound(num.begin(), num.end(), q);
            if (*pos == q)
                cout << q << " found at " << pos - num.begin() + 1 << endl;
            else
                cout << q << " not found" << endl;
        }
    }
    return 0;
}