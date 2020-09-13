#include <iostream>
using namespace std;
int main(void)
{
    int N;
    while (cin >> N)
    {
        int maxLen = 3 * N - 2;
        for (int i = 0; i < N; ++i)
        {
            int len = i * 2 + N, lim = maxLen - len;
            string b(lim, ' '), s(len, '*');
            cout << b << s << endl;
        }
    }
    return 0;
}