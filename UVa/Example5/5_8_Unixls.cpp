#include <iostream>
#include <algorithm>
// #include <fstream>
#include <vector>
#include <string>

using namespace std;

const int max_width = 60;

int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // ifstream filein("input.txt", ios::in);
    // streambuf *backupin = cin.rdbuf();
    // cin.rdbuf(filein.rdbuf());

    int N;
    while (cin >> N)
    {
        vector<string> F;
        string temp;
        int max_length = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            F.push_back(temp);
            if (temp.length() > max_length)
                max_length = temp.length();
        }

        sort(F.begin(), F.end());

        int R, C, row_count;
        C = (max_width + 2) / (max_length + 2);
        row_count = R = (N + C - 1) / C;

        cout << "------------------------------------------------------------" << endl;

        vector<string>::iterator it = F.begin();

        while (row_count-- > 0)
        {
            cout.setf(ios::left);
            cout.width(max_length);
            cout << *it;
            for (int i = 1; i < C; ++i)
            {
                if (it - F.begin() + i * R >= F.size())
                    break;
                cout << "  ";
                cout.setf(ios::left);
                cout.width(max_length);
                cout << *(it + i * R);
            }
            ++it;
            cout << endl;
        }
    }

    // cout.rdbuf(backupout);
    // fileout.close();

    // cin.rdbuf(backupin);
    // filein.close();

    return 0;
}