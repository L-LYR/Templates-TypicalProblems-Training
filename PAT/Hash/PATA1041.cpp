#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int table[10001];
int nums[100001];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        table[nums[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (table[nums[i]] == 1)
        {
            cout << nums[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}