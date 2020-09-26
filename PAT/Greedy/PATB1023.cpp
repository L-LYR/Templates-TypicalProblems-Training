#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int main(void)
{
    int n;
    for (int i = 0; i < 10; ++i)
        cin >> cnt[i];
    // set prefix one
    string ans;
    for (int i = 1; i < 10; ++i)
        if (cnt[i] != 0)
        {
            ans = char(i + '0');
            cnt[i]--;
            break;
        }
    // full fill
    for (int i = 0; i < 10; ++i)
        if (cnt[i] > 0)
            ans.append(cnt[i], char(i + '0'));
    cout << ans << endl;
    return 0;
}