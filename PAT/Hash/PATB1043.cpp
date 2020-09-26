#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
    map<char, int> cm;
    char c;
    int tol = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == 'P' || c == 'A' || c == 'T' ||
            c == 'e' || c == 's' || c == 't')
        {
            cm[c]++;
            tol++;
        }
    }
    while (tol > 0)
    {
        for (const auto &i : "PATest")
        {
            if (cm[i])
            {
                cout << i;
                cm[i]--;
                tol--;
            }
        }
    }
    cout << endl;

    return 0;
}