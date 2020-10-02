#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int m = (nums[i] + p - 1) / p;
        auto j = lower_bound(nums.begin(), next(nums.begin(), i), m) - nums.begin();
        int cur = i - j + 1;
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}