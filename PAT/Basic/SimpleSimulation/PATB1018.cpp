#include <iostream>
using namespace std;

int vcnt[2][3];
int acnt[2][3];
int get_value(char c)
{
    switch (c)
    {
    case 'J':
        return 0;
    case 'C':
        return 1;
    case 'B':
        return 2;
    }
    return -1;
}
char show_max(int i)
{
    int maxVal = vcnt[i][2];
    int index = 2;
    for (int j = 1; j >= 0; --j)
        if (vcnt[i][j] > maxVal)
        {
            maxVal = vcnt[i][j];
            index = j;
        }
    switch (index)
    {
    case 0:
        return 'J';
    case 1:
        return 'C';
    case 2:
        return 'B';
    }
    return 0;
}
int main(void)
{
    int N, a, b;
    cin >> N;
    char c;
    while (--N >= 0)
    {
        cin >> c;
        a = get_value(c);
        cin >> c;
        b = get_value(c);
        if (a == b)
        {
            acnt[0][1]++;
            acnt[1][1]++;
        }
        else if (a == 2 && b == 0)
        {
            acnt[0][2]++;
            acnt[1][0]++;
            vcnt[1][b]++;
        }
        else if (a > b || (a == 0 && b == 2))
        {
            acnt[0][0]++;
            acnt[1][2]++;
            vcnt[0][a]++;
        }
        else
        {
            acnt[0][2]++;
            acnt[1][0]++;
            vcnt[1][b]++;
        }
    }
    for (int i = 0; i < 2; ++i)
        cout << acnt[i][0] << " "
             << acnt[i][1] << " "
             << acnt[i][2] << endl;
    cout << show_max(0);
    cout << " ";
    cout << show_max(1);
    cout << endl;
    return 0;
}