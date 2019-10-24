#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int max_number = 25;
vector<int> pile[max_number];
int N;

const string operation[3] = {"move", "pile", "quit"};
const string direct[2] = {"onto", "over"};

vector<int>::iterator find_block(int target, int &loc)
{
    for (int i = 0; i < N; ++i)
        for (auto j = pile[i].begin(); j != pile[i].end(); ++j)
            if (*j == target)
            {
                loc = i;
                return j;
            }
    return pile[N].end();
}

void clear_above(int loc, vector<int>::iterator pos)
{
    for (auto it = pile[loc].end() - 1; it != pos; --it)
    {
        pile[*it].push_back(*it);
        pile[loc].pop_back();
    }
}

void put_on(int a_loc, int b_loc, vector<int>::iterator ait)
{
    for (auto it = ait; it != pile[a_loc].end(); ++it)
        pile[b_loc].push_back(*it);

    for (auto it = pile[a_loc].end() - 1; it != ait; --it)
        pile[a_loc].pop_back();

    pile[a_loc].pop_back();
}

void print()
{
    for (int i = 0; i < N; ++i)
    {
        cout << i << ":";
        for (auto it = pile[i].begin(); it != pile[i].end(); ++it)
            cout << " " << *it;
        cout << endl;
    }
}

int main(void)
{
    int a, b;
    string opt, dir;
    int a_loc, b_loc;
    vector<int>::iterator ait, bit;

    cin >> N;

    for (int i = 0; i < N; ++i)
        pile[i].push_back(i);

    while (cin >> opt && opt != operation[2])
    {
        cin >> a >> dir >> b;

        if (a == b)
            continue;
        ait = find_block(a, a_loc);
        bit = find_block(b, b_loc);
        if (a_loc == b_loc)
            continue;

        if (dir == direct[0])
            clear_above(b_loc, bit);
        if (opt == operation[0])
            clear_above(a_loc, ait);
        put_on(a_loc, b_loc, ait);
    }
    print();
    return 0;
}