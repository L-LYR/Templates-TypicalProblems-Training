#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int n, i;
    cin >> n;
    vector<string> nums(n);
    for (i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), [](const string &l, const string &r) -> bool {
        // compare with relative weights
        string lr = l + r;
        string rl = r + l;
        return lr < rl;
    });
    string ans;
    for (i = 0; i < n; ++i)
        ans += nums[i];
    for (i = 0; i < ans.length(); ++i) // remove the prefix of many 0s
        if (ans[i] != '0')
            break;
    if (i != ans.length())
        cout << ans.substr(i) << endl;
    else // do not forget the whole-0 case
        cout << 0 << endl;
    return 0;
}