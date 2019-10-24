#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct term
{
    int ex;
    double co;
    term() = default;
    term(int _ex, double _co) { ex = _ex, co = _co; };
};
inline void input(vector<term> &p, int k)
{
    while (--k >= 0)
    {
        term temp;
        cin >> temp.ex >> temp.co;
        p.push_back(temp);
    }
}
int main(void)
{
    int k;
    vector<term> A, B, ans;

    cin >> k;
    input(A, k);
    cin >> k;
    input(B, k);

    int i = 0, j = 0, alen = A.size(), blen = B.size();
    while (i < alen && j < blen)
    {
        if (A[i].ex == B[j].ex)
        {
            A[i].co += B[j].co;
            if (A[i].co != 0) //attention!
                ans.push_back(A[i]);
            ++i;
            ++j;
        }
        else if (A[i].ex > B[j].ex)
            ans.push_back(A[i++]);
        else
            ans.push_back(B[j++]);
    }
    while (i < alen)
        ans.push_back(A[i++]);
    while (j < blen)
        ans.push_back(B[j++]);

    cout << ans.size();
    for (auto p : ans)
        cout << " " << p.ex << fixed << setprecision(1) << " " << p.co;
    cout << endl;
    return 0;
}