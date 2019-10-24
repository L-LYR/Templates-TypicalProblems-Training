#include <bits/stdc++.h>
using namespace std;

char table[12][12];
vector<pair<int, int>> cannon;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
const int bx[4] = {-1, -1, 1, 1}, by[4] = {-1, 1, 1, -1};
const int hx[2][4] = {{-2, -2, 1, 1}, {-1, -1, 2, 2}}, hy[2][4] = {{-1, 1, 2, -2}, {-2, 2, 1, -1}};
int BGX, BGY;

int check(int r, int c)
{
    if (r < 1 || r > 3 || c < 4 || c > 6)
        return 1;
    //R&G
    for (int i = r - 1; i >= 1; --i) //col
        if (table[i][c])
        {
            if (table[i][c] == 'R')
                return 1;
            else
                break;
        }
    for (int i = r + 1; i <= 10; ++i)
        if (table[i][c])
        {
            if (table[i][c] == 'R')
                return 1;
            else if (table[i][c] == 'G' && BGY != c)
                return 1;
            else
                break;
        }
    for (int i = c - 1; i >= 1; --i) //row
        if (table[r][i])
        {
            if (table[r][i] == 'R')
                return 1;
            else
                break;
        }
    for (int i = c + 1; i <= 9; ++i)
        if (table[r][i])
        {
            if (table[r][i] == 'R')
                return 1;
            else
                break;
        }
    //H
    for (int i = 0; i < 4; ++i)
    {
        int br = r + bx[i], bc = c + by[i];
        if (br < 1)
            continue;
        if (table[br][bc] == 0)
        {
            if (table[r + hx[0][i]][c + hy[0][i]] == 'H')
                return 1;
            if (table[r + hx[1][i]][c + hy[1][i]] == 'H')
                return 1;
        }
    }
    //C
    for (int i = 0; i < cannon.size(); ++i)
    {
        int count;
        if (cannon[i].first == r)
        {
            count = 0;
            for (int j = c - 1; j > cannon[i].second; --j)
                if (table[r][j])
                    ++count;
            if (count == 1)
                return 1;
            count = 0;
            for (int j = c + 1; j < cannon[i].second; ++j)
                if (table[r][j])
                    ++count;
            if (count == 1)
                return 1;
        }
        if (cannon[i].second == c)
        {
            count = 0;
            for (int j = r - 1; j > cannon[i].first; --j)
                if (table[j][c])
                    ++count;
            if (count == 1)
                return 1;
            count = 0;
            for (int j = r + 1; j < cannon[i].first; ++j)
                if (table[j][c])
                    ++count;
            if (count == 1)
                return 1;
        }
    }
    return 0;
}

int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // ifstream filein("input.txt", ios::in);
    // streambuf *backupin = cin.rdbuf();
    // cin.rdbuf(filein.rdbuf());

    int N;
    while (cin >> N && N != 0)
    {
        cin >> BGX >> BGY;

        memset(table, 0, sizeof(table));
        cannon.resize(0);

        char chess;
        int x, y;

        for (int i = 0; i < N; ++i)
        {
            cin >> chess >> x >> y;
            table[x][y] = chess;
            if (chess == 'C')
                cannon.push_back({x, y});
        }

        int direct = 0;
        for (int i = 0; i < 4; ++i)
            direct += check(BGX + dx[i], BGY + dy[i]);
        if (direct == 4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    // cout.rdbuf(backupout);
    // fileout.close();

    // cin.rdbuf(backupin);
    // filein.close();
    return 0;
}
/*
2 1 4
G 10 5
R 6 4

3 1 5
H 4 5
G 10 5
C 7 5
*/