/*
题目修正
1 如果精确匹配1个 输出精确匹配
2 如果精确匹配多个 输出精确匹配中字典序最小的 + '!'
3 如果模糊匹配0个 输出字典中字典序最小的 + '?"
4 如果模糊匹配多个 输出模糊匹配中字典序最小的 +'?"
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int judge(string a, string b)
{
    if (a.length() < b.length())
        swap(a, b);
    if (b == a.substr(0, b.length()))
        return a.length() - b.length();
    else
        return INF;
}
string query(string a, map<string, string> &dic)
{
    string ans;
    int diff = 0, mdiff = INF;
    int cnt = 0;
    for (auto i : dic)
    {
        if (i.second == a)
        {
            if (cnt)
                return ans + '!';
            ++cnt;
            ans = i.first;
            mdiff = 0;
        }
        else
        {
            diff = judge(a, i.second);
            if (diff <= mdiff)
            {
                ans = i.first;
                mdiff = diff;
            }
        }
    }
    if (mdiff)
        ans += '?';
    return ans;
}
int main(void)
{
    map<char, string> encode;
    map<string, string> cnxt;
    char c;
    string code, str;
    while (cin >> c && c != '*')
    {
        cin >> code;
        encode.insert(make_pair(c, code));
        // cout << c << " " << code << endl;
    }
    string word;
    while (cin >> str && str[0] != '*')
    {
        for (auto i : str)
            word.append(encode[i]);
        cnxt.insert(make_pair(str, word));
        // cout << word << endl;
        word.clear();
    }
    while (cin >> str && str[0] != '*')
        cout << query(str, cnxt) << endl;

    return 0;
}