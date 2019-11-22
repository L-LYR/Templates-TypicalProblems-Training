#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    string ans;
    ans.insert(ans.length(), n / 100, 'B');
    ans.insert(ans.length(), n % 100 / 10, 'S');
    for (int i = 1; i <= n % 10; ++i)
        ans += to_string(i);
    cout << ans << endl;
    return 0;
}