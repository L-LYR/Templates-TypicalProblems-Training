#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    int score[1005], t, s;
    memset(score, 0, sizeof(score));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d-%*d %d", &t, &s);
        score[t] += s;
    }
    int max_val = 0, max_idx = 0;
    for (int i = 0; i < 1005; ++i)
    {
        if (score[i] > max_val)
        {
            max_val = score[i];
            max_idx = i;
        }
    }

    cout << max_idx << " " << max_val << endl;
    return 0;
}