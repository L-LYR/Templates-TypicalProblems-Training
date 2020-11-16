#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
unordered_map<int, int> mp[maxn];
int f[maxn], s[maxn];
void init(int n) {
    generate(f, f + n + 1, [n = 0]() mutable { return n++; });
    fill(s, s + n + 1, 1);
}

int find(int x) { return (f[x] == x) ? x : (f[x] = find(f[x])); }

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (s[fx] < s[fy]) {
        f[fx] = f[fy];
        s[fy] += s[fx];
        for (auto it : mp[fx]) mp[fy][it.first] += it.second;
    } else {
        f[fy] = f[fx];
        s[fx] += s[fy];
        for (auto it : mp[fy]) mp[fx][it.first] += it.second;
    }
}

int main() {
    int n, q, a, b, c;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        mp[i][a]++;
    }
    init(n);
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1)
            merge(b, c);
        else
            cout << mp[find(b)][c] << endl;
    }

    return 0;
}
