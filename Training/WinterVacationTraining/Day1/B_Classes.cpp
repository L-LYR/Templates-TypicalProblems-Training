#include <iostream>
#include <algorithm>

using namespace std;

inline bool isLegal(int a, int b, int c, int ab, int bc, int ac, int abc)
{
    int part_a = ab + ac - abc;
    int part_b = ab + bc - abc;
    int part_c = ac + bc - abc;
    bool C_a = (a >= ab) && (a >= ac) && (a >= abc) && (a >= part_a);
    bool C_b = (b >= ab) && (b >= bc) && (b >= abc) && (b >= part_b);
    bool C_c = (c >= bc) && (c >= ac) && (c >= abc) && (c >= part_c);
    bool C_u = (ab >= abc) && (bc >= abc) && (ac >= abc);
    return C_a && C_b && C_c && C_u;
}

int main(void)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        int a, b, c, ab, bc, ac, abc;
        int ans = -1;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> c >> ab >> bc >> ac >> abc;
            if (isLegal(a, b, c, ab, bc, ac, abc))
            {
                int cur = a + b + c - ab - bc - ac + abc;
                ans = max(ans, cur);
            }
        }
        cout << ans << endl;
    }

    return 0;
}