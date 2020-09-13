#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    string n;
    while (cin >> n)
    {
        int len = n.length();
        vector<int> x;
        for (int i = 0; i < len; ++i)
            x.push_back(n[len - 1 - i] - '0');
        n.clear();
        do
        {
            len = x.size();
            n.push_back((char)(x[0] % 2 + '0'));
            for (int i = len - 1; i > 0; --i)
            {
                if (x[i] % 2)
                    x[i - 1] += 10;
                x[i] /= 2;
            }
            x[0] /= 2;
            if (x[len - 1] == 0)
                x.pop_back();
        } while (!x.empty());
        reverse(n.begin(), n.end());
        cout << n << endl;
        n.clear();
    }
    return 0;
}