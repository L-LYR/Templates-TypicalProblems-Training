#include <iostream>

using namespace std;

string bind[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};
int main(void)
{
    string str;
    cin >> str;
    int sum = 0;
    for (auto i : str)
        sum += i - '0';
    string ans = to_string(sum);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << bind[ans[i] - '0'];
        if (i != ans.length() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}