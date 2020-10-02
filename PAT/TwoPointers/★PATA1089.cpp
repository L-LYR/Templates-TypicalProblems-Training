#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool isSame(const vector<int> &l, const vector<int> &r) {
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] != r[i]) return false;
    }
    return true;
}

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

bool ret = false;
void insertionSort(const vector<int> &prev, const vector<int> &now) {
    vector<int> cur = prev;

    for (int i = 1; i < cur.size() && !ret; ++i) {
        if (i > 1 && isSame(cur, now)) {
            ret = true;
        }
        int temp = cur[i], j = i;
        while (j > 0 && cur[j - 1] > temp) {
            cur[j] = cur[j - 1];
            j--;
        }
        cur[j] = temp;
    }
    if (ret) {
        cout << "Insertion Sort" << endl;
        print(cur);
    }
}

void mergeSort(const vector<int> &prev, const vector<int> &now) {
    vector<int> cur = prev;
    for (int s = 2; s / 2 <= cur.size() && !ret; s *= 2) {
        if (s > 2 && isSame(cur, now)) {
            ret = true;
        }
        for (int i = 0; i < cur.size(); i += s) {
            sort(cur.begin() + i, cur.begin() + min(i + s, (int)cur.size()));
        }
    }
    if (ret) {
        cout << "Merge Sort" << endl;
        print(cur);
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> prev(n), now(n);
    for (int i = 0; i < n; ++i) {
        cin >> prev[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> now[i];
    }

    insertionSort(prev, now);
    if (!ret)
        mergeSort(prev, now);

    return 0;
}