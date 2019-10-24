#include <iostream>
#include <algorithm>
using namespace std;
int a[6] = {4, 8, 15, 16, 23, 42};
bool next_permutation(int a[], int len)
{
    int j = len - 2;
    while (a[j] > a[j + 1])
        j--;
    int k = len - 1;
    while (a[j] > a[k])
        k--;
    if (j == k)
        return false;
    swap(a[j], a[k]);
    int r = len - 1, s = j + 1;
    while (r > s)
    {
        swap(a[r], a[s]);
        r--;
        s++;
    }
    return true;
}
int main(void)
{
    int q[4];
    int i;
    for (i = 0; i < 4; ++i)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cout.flush();
        cin >> q[i];
    }
    do
    {
        bool flag = true;
        for (i = 0; i < 4; ++i)
            if (q[i] != a[i] * a[i + 1])
            {
                flag = false;
                break;
            }
        if (flag)
            break;
    } while (next_permutation(a, 6));
    cout << "!";
    for (i = 0; i < 6; ++i)
        cout << " " << a[i];
    cout << endl;
    return 0;
}