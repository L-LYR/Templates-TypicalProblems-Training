#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string num;
    int n;
    cin >> num >> n;
    int len = num.length();

    vector<int> bnum(len);
    for (int i = 0; i < len; ++i) {
        bnum[i] = num[i] - '0';
    }
    vector<int> di(len);
    int r = 0;
    for (int i = 0; i < len; ++i) {
        r = r * 10 + bnum[i];
        if (r < n)
            di[i] = 0;
        else {
            di[i] = r / n;
            r = r % n;
        }
    }
    int i = 0;
    while (di[i] == 0 && i < len - 1) {
        i++;
    }
    while (i < len) {
        cout << di[i];
        i++;
    }
    cout << " " << r << endl;

    return 0;
}