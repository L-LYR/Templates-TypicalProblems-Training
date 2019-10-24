#include <iostream>
using namespace std;
int main(void)
{
    int T;
    int64_t A, B, C;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> A >> B >> C;
        cout << "Case #" << i << ": " << ((A + B > C) ? "true" : "false") << endl;
    }
    return 0;
}