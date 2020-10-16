#include <iostream>
#include <string>

using namespace std;
// we use x, y, z to denote the number of 'A' 
// on the left side of 'P', between 'P' and 'T'
// and on the right side of 'T'.
// basic case sPATs: x = k, y = 1, z = k
// general case aPbTc --> aPbATca : x_i+1 = x_i, y_i+1 = y_i + 1, z_i+1 = z_i + x_i
// z = y * x

int main(void) {
    int n;
    cin >> n;
    while (n-- > 0) {
        string str;
        cin >> str;
        int i = 0, t = 0;
        int cnt[3];
        while (i < str.length() && str[i] == 'A') {
            i++;
        }
        if (i >= str.length() || str[i] != 'P') {
            cout << "NO" << endl;
            continue;
        } else {
            cnt[0] = i - t;
            i++;
            t = i;
        }
        while (i < str.length() && str[i] == 'A') {
            i++;
        }
        if (i >= str.length() || str[i] != 'T') {
            cout << "NO" << endl;
            continue;
        } else {
            cnt[1] = i - t;
            i++;
            t = i;
        }
        while (i < str.length() && str[i] == 'A') {
            i++;
        }
        if (i < str.length() && str[i] != 'A') {
            cout << "NO" << endl;
            continue;
        }
        cnt[2] = i - t;
        if (cnt[0] >= 0 && cnt[1] == 1 && cnt[2] >= 0) {
            cout << "YES" << endl;
        } else if (cnt[0] >= 0 && cnt[2] >= cnt[0] &&
                   cnt[1] >= 1 && cnt[1] * cnt[0] == cnt[2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}