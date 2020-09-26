#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void)
{
    string s, w;
    cin >> s >> w;

    unordered_map<char, int> cm, wm;
    for (const auto &i : s)
        cm[i]++;

    for (const auto &i : w)
        wm[i]++;
    int ans = 0;
    for (const auto &i : wm)
        if (cm[i.first] < i.second)
            ans += i.second - cm[i.first];
    if (ans > 0)
        cout << "No " << ans << endl;
    else
        cout << "Yes " << s.length() - w.length() << endl;

    return 0;
}