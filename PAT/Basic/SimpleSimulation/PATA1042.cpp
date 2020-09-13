#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<int, string> dic;
vector<int> cards(60, 0);
vector<int> temp(60, 0);
int trail[60];
string c[5] = {"S", "H", "C", "D", "J"};
void shuffle(void)
{
    int i, j;
    for (i = 1; i <= 54; ++i)
    {
        j = trail[i];
        temp[j] = cards[i];
    }
    cards.swap(temp);
}
int main(void)
{
    int K, i;
    cin >> K;
    for (i = 1; i <= 54; ++i)
    {
        cin >> trail[i];
        cards[i] = i;
    }

    for (i = 0; i < 4; ++i)
        for (int j = 1; j <= 13; ++j)
        {
            string card = c[i] + to_string(j);
            dic.insert(make_pair(i * 13 + j, card));
        }
    dic.insert(make_pair(53, c[4] + '1'));
    dic.insert(make_pair(54, c[4] + '2'));
    while (--K >= 0)
        shuffle();
    for (i = 1; i < 54; ++i)
    {
        cout << dic[cards[i]] << " ";
    }
    cout << dic[cards[i]] << endl;
    return 0;
}