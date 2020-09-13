#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    int n;
    cin >> n;
    getchar();
    string suffix, str;
    getline(cin, suffix);
    for (int i = 0; i < n - 1; ++i)
    {
        getline(cin, str);
        int j = suffix.length() - 1;
        int k = str.length() - 1;
        while (j >= 0 && k >= 0)
        {
            if (suffix[j] != str[k])
                break;
            else
            {
                j--;
                k--;
            }
        }
        suffix = suffix.substr(j + 1);
    }

    if (suffix == "")
        cout << "nai" << endl;
    else
        cout << suffix << endl;

    return 0;
}