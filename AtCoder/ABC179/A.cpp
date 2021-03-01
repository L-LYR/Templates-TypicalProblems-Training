#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string cur;
    cin >> cur;
    if (cur.back() != 's')
        cout << cur.append("s") << endl;
    else
        cout << cur.append("es") << endl;
    return 0;
}