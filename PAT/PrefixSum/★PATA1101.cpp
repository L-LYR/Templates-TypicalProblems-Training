#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
int lmax[maxn];
int rmin[maxn];

int main(void) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    rmin[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rmin[i] = min(rmin[i + 1], nums[i]);
    }
    lmax[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        lmax[i] = max(lmax[i - 1], nums[i]);
    }
    vector<int> ans;
    if (nums[0] <= rmin[1]) ans.push_back(nums[0]);
    for (int i = 1; i < n - 1; ++i) {
        if (nums[i] > rmin[i + 1]) continue;
        if (nums[i] < lmax[i - 1]) continue;
        ans.push_back(nums[i]);
    }
    if (nums[n - 1] >= lmax[n - 2]) ans.push_back(nums[n - 1]);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
// 1 2 2 4 5
// 1 3 3 4 5
// 5
// 1 3 2 4 5