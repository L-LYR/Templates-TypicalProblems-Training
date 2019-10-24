#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 80;
const int row_max = 10010;
const int col_max = 11;

typedef pair<int, int> IDpair;

int IDbase[row_max][col_max];

map<string, int> IDmap;
map<IDpair, int> repeat_pair_map;

int row_ans_1, row_ans_2, col_ans_1, col_ans_2;

int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // FILE *f = freopen("input.txt", "r", stdin);

    int row, col;
    char buffer[BUFFER_SIZE];
    string str;
    int flag, ID;
    IDpair temp;

    while (cin >> row >> col)
    {
        ID = flag = 1;
        memset(IDbase, 0, sizeof(IDbase));
        IDmap.clear();

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
            {
                getchar();
                scanf("%[^,\n]", buffer);
                str = buffer;
                if (IDmap.count(str) == 0)
                {
                    IDmap.insert(make_pair(str, ID));
                    ++ID;
                }
                IDbase[i][j] = IDmap[str];
            }

        for (int i = 0; i < col - 1 && flag == 1; ++i)
        {
            for (int j = i + 1; j < col && flag == 1; ++j)
            {
                repeat_pair_map.clear();
                for (int k = 0; k < row; ++k)
                {
                    temp = make_pair(IDbase[k][i], IDbase[k][j]);
                    if (repeat_pair_map.count(temp) == 1)
                    {
                        flag = 0;
                        row_ans_1 = repeat_pair_map[temp];
                        row_ans_2 = k + 1;
                        col_ans_1 = i + 1;
                        col_ans_2 = j + 1;
                        break;
                    }
                    else
                        repeat_pair_map[temp] = k + 1;
                }
            }
        }

        if (flag == 1)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
            cout << row_ans_1 << " " << row_ans_2 << endl
                 << col_ans_1 << " " << col_ans_2 << endl;
        }
    } //while

    // cout.rdbuf(backupout);
    // fileout.close();

    // fclose(f);
    return 0;
}