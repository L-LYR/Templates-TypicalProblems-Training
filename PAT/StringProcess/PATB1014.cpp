#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string dic[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(void)
{
    string a, b;
    int ans[3], cnt = 0;
    cin >> a >> b;
    for (int i = 0; i < min(a.length(), b.length()); ++i)
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9')) && cnt == 1)
        {
            ans[cnt++] = (isalpha(a[i]) ? a[i] - 'A' + 10 : a[i] - '0');
            break;
        }
        else if (isalpha(a[i]) && (a[i] >= 'A') && (a[i] <= 'G') && a[i] == b[i])
            ans[cnt++] = a[i] - 'A';
    cin >> a >> b;
    for (int i = 0; i < min(a.length(), b.length()); ++i)
        if (isalpha(a[i]) && a[i] == b[i])
        {
            ans[cnt++] = i;
            break;
        }

    cout << dic[ans[0]] << " "
         << setw(2) << setfill('0') << ans[1] << ":"
         << setw(2) << setfill('0') << ans[2] << endl;
    return 0;
}