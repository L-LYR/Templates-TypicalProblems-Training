#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;
int main(void)
{
    char number[maxn];
    int k, num[maxn];
    while (scanf("%s%d", number, &k) != EOF)
    {
        int len = strlen(number);
        memset(num, 0, sizeof(num)); // important!!!!!!
        for (int i = 0; i < len; ++i)
            num[i] = number[i] - '0';
        while (k-- > 0)
        {
            int i, j;
            for (i = 0; i < len; ++i) // find the increasing sub-array
            {
                if (num[i] > 0)
                {
                    for (j = i + 1; j < len; ++j)
                        if (num[j] >= 0)
                            break;
                    if (num[i] > num[j])
                    {
                        num[i] = -1;
                        break;
                    }
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < len; ++i)
        {
            if ((flag == 0 && num[i] > 0) || (flag == 1 && num[i] >= 0))
            {
                cout << num[i];
                if (flag == 0)
                    flag = 1;
            }
        }
        if (flag == 0)
            cout << 0;
        cout << endl;
    }

    return 0;
}