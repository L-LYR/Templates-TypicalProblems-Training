#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int school[maxn];

int main(void)
{
    int n, i, maxVal = -1, temp;
    cin >> n;
    for (int k = 0; k < n; ++k)
    {
        cin >> i >> temp;
        school[i] += temp;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (school[j] > maxVal)
        {
            i = j;
            maxVal = school[j];
        }
    }
    cout << i << " " << maxVal << endl;
    return 0;
}