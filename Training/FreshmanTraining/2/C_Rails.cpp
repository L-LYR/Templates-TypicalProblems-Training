#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N;
    while (cin >> N && N != 0)
    {
        int t;
        while (cin >> t && t != 0)
        {
            vector<int> lq(N);
            lq[0] = t;
            for (int i = 1; i < N; ++i)
                cin >> lq[i];
            bool flag = true;
            for (int i = 0; i < N - 1; ++i)
            {
                int last = lq[i];
                for (int j = i + 1; j < N; ++j)
                {
                    if (lq[j] > lq[i])
                        continue;
                    if (last > lq[j])
                        last = lq[j];
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                    break;
            }
            cout << ((flag == true) ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}