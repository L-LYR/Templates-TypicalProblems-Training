#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<int, int> nums;

int main(void)
{
    int n, p, num;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums[num]++;
    }

    for (auto i : nums)
    {
        int j = p - i.first;
        if (nums.count(j))
        {
            if (j != i.first)
            {
                cout << i.first << " " << j << endl;
                return 0;
            }
            if (j == i.first && nums[j] == 2)
            {
                cout << j << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}