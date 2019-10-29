#include <iostream>
#include <algorithm>
using namespace std;
struct creature
{
    long long hp, dmg;
    long long dif;
    creature(long long _hp = 0, long long _dmg = 0)
    {
        hp = _hp, dmg = _dmg;
        dif = 0;
    };
};
const int maxn = 200005;
creature c[maxn];
int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;

    b = min(b, n); //maybe b > n

    for (int i = 0; i < n; ++i)
    {
        cin >> c[i].hp;
        cin >> c[i].dmg;
        c[i].dif = c[i].hp - c[i].dmg;
    }

    sort(c, c + n, [](const creature &a, const creature &b) -> bool {
        return a.dif > b.dif;
    });

    // for (int i = 0; i < b; ++i)
    //     if (c[i].dif > 0)
    //         c[i].dmg = c[i].hp;

    long long sum = 0;
    // for (int i = 0; i < n; ++i)
    //     sum += c[i].dmg;

    for (int i = 0; i < b; ++i)
        sum += max(c[i].dmg, c[i].hp);

    for (int i = b; i < n; ++i)
        sum += c[i].dmg;

    long long ans = sum;
    if (b > 0)
    {
        for (int i = 0; i < b; ++i)
            ans = max(ans, (sum - max(c[i].dmg, c[i].hp) + (c[i].hp << a)));
        sum = sum - max(c[b - 1].dmg, c[b - 1].hp) + c[b - 1].dmg; //pay attention
        //Maybe we will use the second type of spell in the next recurrance
        for (int i = b; i < n; ++i)
            ans = max(ans, (sum - c[i].dmg + (c[i].hp << a)));
    }
    cout << ans << endl;
    return 0;
}