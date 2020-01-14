#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void)
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        string s, t;
        cin >> s >> t;
        int cnt = 0, len = s.length(), flag = 1;
        //Firstly transfer "? 0" to "0 0"
        for (int j = 0; j < len; ++j)
            if (s[j] == '?' && t[j] == '0')
            {
                s[j] = '0';
                ++cnt;
            }
        //Secondly exchange "0 1" with "1 0" into "0 0" and "1 1"
        for (int j = 0; j < len; ++j)
        {
            if (s[j] != t[j] && s[j] != '?')
            {
                for (int k = j + 1; k < len; ++k)
                {
                    if (s[k] == t[j] && s[k] != t[k])
                    {
                        swap(s[k], s[j]);
                        ++cnt;
                        break;
                    }
                }
            }
        }
        for (int j = 0; j < len; ++j)
        {
            if (s[j] != t[j])
            {
                if (s[j] == '0') //just transfer '0' tp '1'
                {
                    s[j] = t[j];
                    ++cnt;
                }
                else if (s[j] == '?') //find "0 1" or "1 0" swap
                {
                    for (int k = j + 1; k < len; ++k)
                    {
                        if (s[k] == t[j] && s[k] != t[k])
                        {
                            swap(s[k], s[j]);
                            ++cnt;
                            break;
                        }
                    }
                    if (s[j] == '?') //if not juat transfer "?"
                    {
                        s[j] = t[j];
                        ++cnt;
                    }
                }
                else if (s[j] == '1') //can only find "?"
                {
                    for (int k = j + 1; k < len; ++k)
                    {
                        if (s[k] == '?' && s[j] == t[k])
                        {
                            s[k] = s[j];
                            s[j] = t[j];
                            cnt += 2;
                            break;
                        }
                    }
                }
            }
        }
        cout << "Case " << i << ": " << ((s == t) ? cnt : -1) << endl;
    }
    return 0;
}