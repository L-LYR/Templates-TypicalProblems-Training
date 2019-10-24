#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // ifstream filein("input.txt", ios::in);
    // streambuf *backupin = cin.rdbuf();
    // cin.rdbuf(filein.rdbuf());

    int n, m, Problem = 0;
    while (cin >> n >> m)
    {
        if (Problem)
            cout << endl
                 << "**********************************"
                 << endl
                 << endl;
        cout << "Problem #" << ++Problem << endl
             << endl;
        vector<vector<int>> h(n + 1, vector<int>(n + 1, 0)), v(n + 1, vector<int>(n + 1, 0));
        char cmd;
        int r, c;
        while (--m >= 0)
        {
            cin >> cmd >> r >> c;
            (cmd == 'H') ? h[r][c] = 1 : v[c][r] = 1;
        }
        int total = 0;

        for (int l = 1; l <= n; ++l) //size
        {
            int squares = 0;
            for (int i = 1; i <= n - l; ++i)
            {
                for (int j = 1; j <= n - l; ++j)
                {
                    bool flag = true;
                    for (int k = 0; k < l; ++k)
                    {
                        if (!(h[i][j + k] && h[i + l][j + k] && v[i + k][j] && v[i + k][j + l]))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        ++squares;
                        ++total;
                    }
                }
            }
            if (squares)
                cout << squares << " square (s) of size " << l << endl;
        }
        if (!total)
            cout << "No completed squares can be found." << endl;
    }
    // cout.rdbuf(backupout);
    // fileout.close();

    // cin.rdbuf(backupin);
    // filein.close();
    return 0;
}