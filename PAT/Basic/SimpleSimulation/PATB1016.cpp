#include <iostream>
using namespace std;
uint64_t get_part(uint64_t x, uint64_t tar)
{
    uint64_t mod, ans = 0;
    while (x)
    {
        mod = x % 10;
        if (mod == tar)
        {
            ans = ans * 10 + mod;
        }
        x /= 10;
    }
    return ans;
}
int main(void)
{
    uint64_t A, B;
    uint64_t a, b;
    cin >> A >> a >> B >> b;
    uint64_t x = get_part(A, a);
    uint64_t y = get_part(B, b);
    cout << x + y << endl;
    return 0;
}