#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> vi(n);
    for (int i = 0; i < n; ++i)
        cin >> vi[i];

    // vi can be seen as a union-find set.
    // If there be a circle with e edges, we need e-1 swap operations.
    // Supposing that there are n circles, the minimum number of swap operations is n * (ei - 1).
    // However, we can only use the Swap(0, *) operation, that is to say:
    // For one case, number 0 is in the circle, the answer will still be e - 1.
    // For another case, number 0 isn't in the circle, we need to add 0 to this circle, 
    // which will increase tha answer by 1.
    // After that the new circle will have e' = e + 1 edges, so the answer will be e' - 1 + 1 = e + 1.

    // Suppose that there are m circles without number 0, we can generate the answer as below:
    //                                   n * (ei - 1) + 2 * m

    int ans = 0, i = 0, c = 0;
    if (vi[0] != 0)
        c = -1;
    for (int i = 0; i < n; ++i)
    {
        if (vi[i] == i)
            continue;
        else
            c++;
        while (vi[i] != i)
        {
            swap(vi[i], vi[vi[i]]);
            ans++;
        }
    }
    cout << ans + 2 * c << endl;
    return 0;
}