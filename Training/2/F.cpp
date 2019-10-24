#include <iostream>
using namespace std;
int ans[3005];
int visited[50005];
int main(void)
{
    int cnt = 1;
    for (int i = 2; i < 50005; ++i)
    {
        if (!visited[i])
        {
            ans[cnt] = i;
            ++cnt;
            int cont = 0;
            for (int j = i + 1; j < 50005; j++)
            {
                if (visited[j] == 0)
                    cont++;
                if (cont % i == 0)
                    visited[j] = 1;
            }
            if (cnt > 3000)
                break;
        }
    }
    int q;
    while (cin >> q)
        cout << ans[q] << endl;
    return 0;
}