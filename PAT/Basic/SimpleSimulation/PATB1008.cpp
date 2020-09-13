#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int N, K;
    cin >> N >> K;
    K %= N;
    vector<int> ans(N);
    for (int i = 0; i < N; ++i)
        cin >> ans[i];
    reverse(ans.begin(), ans.end());
    reverse(ans.begin(), ans.begin() + K);
    reverse(ans.begin() + K, ans.end());
    cout << ans[0];
    for (int i = 1; i < N; ++i)
        cout << " " << ans[i];
    return 0;
}