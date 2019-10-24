#include <iostream>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int64_t a, b, c;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        //judge whether it is overflow(upper)
        if (a > 0 && b > 0 && (int64_t)((uint64_t)a + (uint64_t)b) <= 0)
        {
            cout << "true" << endl;
            continue;
        }
        //judge whether it is overflow(below)
        if (a < 0 && b < 0 && (int64_t)((uint64_t)a + (uint64_t)b) >= 0)
        {
            cout << "false" << endl;
            continue;
        }
        if (a + b > c)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}