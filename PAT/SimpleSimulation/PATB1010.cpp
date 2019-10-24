#include <iostream>
#include <vector>
using namespace std;
vector<int> poly;
int main(void)
{
    int k, n;
    while (cin >> k >> n)
    {
        if (k == 0)
        {
            poly.push_back(k);
            poly.push_back(n);
        }
        if (n != 0)
        {
            poly.push_back(k * n);
            poly.push_back(n - 1);
        }
    }
    if (poly.empty())
        cout << "0 0" << endl;
    else
    {
        int i, len = poly.size();
        for (i = 0; i < len - 1; ++i)
            cout << poly[i] << " ";
        cout << poly[i] << endl;
    }
    return 0;
}