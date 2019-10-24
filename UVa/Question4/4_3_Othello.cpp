#include <bits/stdc++.h>
using namespace std;

// int cmp(pair<int, int> x, pair<int, int> y)
// {
//     if (x.first < y.first)
//         return 1;
//     else if (x.first > y.first)
//         return 0;
//     else
//         return (x.second < y.second);
// }

class othello
{
private:
    char board[11][11];
    char curPlayer;
    char rival;
    const char blank = '-';
    int w = 0, b = 0;
    // vector<pair<int, int>> moves;
    set<pair<int, int>> moves;
    const int x[8] = {0, 1, 1, -1, 1, -1, -1, 0};
    const int y[8] = {1, 0, 1, 1, -1, -1, 0, -1};

    void search(char target, int r, int c, int d, bool change = false)
    {
        int xd = r + x[d];
        int yd = c + y[d];
        int gap = 0;
        if (xd >= 0 && yd >= 0 && xd < 8 && yd < 8 && board[xd][yd] == rival)
        {
            while (xd >= 0 && yd >= 0 && xd < 8 && yd < 8 && board[xd][yd] == rival)
            {
                xd += x[d];
                yd += y[d];
                ++gap;
            }
            if (xd >= 0 && yd >= 0 && xd < 8 && yd < 8 && board[xd][yd] == target && gap)
            {
                if (change)
                {
                    xd = r + x[d];
                    yd = c + y[d];
                    while (board[xd][yd] == rival)
                    {
                        board[xd][yd] = curPlayer;
                        if (curPlayer == 'W')
                        {
                            ++w;
                            --b;
                        }
                        else
                        {
                            ++b;
                            --w;
                        }
                        xd += x[d];
                        yd += y[d];
                    }
                }
                else
                {
                    // cout << xd << " " << yd << endl;
                    // cout << r << " " << c << endl;
                    if (target == curPlayer)
                        // moves.push_back({r, c});
                        moves.insert({r, c});
                    else
                        // moves.push_back({xd, yd});
                        moves.insert({xd, yd});
                }
            }
        }
    }
    void findMoves()
    {
        // moves.resize(0);
        moves.clear();
        for (int r = 0; r < 8; ++r)
            for (int c = 0; c < 8; ++c)
            {
                if (board[r][c] == curPlayer)
                {
                    for (int k = 0; k < 8; ++k)
                        search(blank, r, c, k);
                }
                else if (board[r][c] == blank)
                {
                    for (int k = 0; k < 8; ++k)
                        search(curPlayer, r, c, k);
                }
            }
    }

public:
    othello(istream &in)
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
            {
                in >> board[i][j];
                if (board[i][j] == 'W')
                    ++w;
                else if (board[i][j] == 'B')
                    ++b;
            }
        cin >> curPlayer;
        rival = (curPlayer == 'W') ? 'B' : 'W';
    }
    void listMoves()
    {
        findMoves();
        if (moves.empty())
        {
            cout << "No legal move.";
            swap(curPlayer, rival);
            findMoves();
        }
        else
        {
            // sort(moves.begin(), moves.end(), cmp);
            // cout << "(" << moves[0].first + 1 << "," << moves[0].second + 1 << ")";
            // for (int i = 1; i < moves.size(); ++i)
            // cout << " (" << moves[i].first + 1 << "," << moves[i].second + 1 << ")";
            int count = moves.size();
            for (auto &i : moves)
            {
                cout << "(" << i.first + 1 << "," << i.second + 1 << ")";
                if (--count)
                    cout << " ";
            }
        }
        cout << endl;
    }
    void move(int r, int c)
    {
        board[r][c] = curPlayer;
        if (curPlayer == 'W')
            ++w;
        else
            ++b;
        for (int k = 0; k < 8; ++k)
            search(curPlayer, r, c, k, true);
        // show();
        cout << "Black - " << setw(2) << b << " White - " << setw(2) << w << endl;
        swap(curPlayer, rival);
    }
    void show()
    {
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
                cout << board[i][j];
            cout << endl;
        }
    }
    ~othello() = default;
};
int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // ifstream filein("input.txt", ios::in);
    // streambuf *backupin = cin.rdbuf();
    // cin.rdbuf(filein.rdbuf());

    int N;
    cin >> N;
    while (--N >= 0)
    {
        othello A(cin);
        string cmd;
        while (cin >> cmd && cmd[0] != 'Q')
        {
            if (cmd[0] == 'L')
                A.listMoves();
            else
                A.move(cmd[1] - '0' - 1, cmd[2] - '0' - 1);
        }
        if (cmd[0] == 'Q')
            A.show();
        if (N)
            cout << endl;
    }
    // cout.rdbuf(backupout);
    // fileout.close();

    // cin.rdbuf(backupin);
    // filein.close();
    return 0;
}