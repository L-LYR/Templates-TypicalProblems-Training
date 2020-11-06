#include <iostream>
#include <queue>

using namespace std;
const int maxn = 1e5;
int n, k;
int visited[maxn + 5];
int main(void) {
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c == k) {
            cout << visited[c] << endl;
            break;
        }
        if (c + 1 <= maxn && !visited[c + 1]) {
            q.push(c + 1);
            visited[c + 1] = visited[c] + 1;
        }
        if (c * 2 <= maxn && !visited[c * 2]) {
            q.push(2 * c);
            visited[c * 2] = visited[c] + 1;
        }
        if (c - 1 >= 0 && !visited[c - 1]) {
            q.push(c - 1);
            visited[c - 1] = visited[c] + 1;
        }
    }
    return 0;
}
