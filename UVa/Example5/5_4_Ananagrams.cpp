#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> words;
vector<string> input, ans;

string format(const string &input)
{
    string fmt = input;
    for (auto &i : fmt)
        i = tolower(i);
    sort(fmt.begin(), fmt.end());
    return fmt;
}

int main(void)
{
    string temp, fmt;
    while (cin >> temp && *(temp.begin()) != '#')
    {
        input.push_back(temp);
        ++words[format(temp)];
    }
    for (const auto &i : input)
        if (words[format(i)] == 1)
            ans.push_back(i);
    sort(ans.begin(), ans.end());
    for (const auto &i : ans)
        cout << i << endl;
    return 0;
}