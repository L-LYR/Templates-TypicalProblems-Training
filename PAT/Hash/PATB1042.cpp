#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    map<char, int> cm;
    char c;
    while ((c = getchar()) != EOF)
        if (isalpha(c))
            cm[tolower(c)]++;
    auto ans = *max_element(cm.begin(), cm.end(), [](const pair<char, int> &l, const pair<char, int> &r) -> bool {
        return l.second < r.second;
    });
    cout << ans.first << " " << ans.second << endl;

    return 0;
}