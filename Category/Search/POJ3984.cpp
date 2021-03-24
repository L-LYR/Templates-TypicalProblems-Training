#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int maxn = 6;
int maze[maxn][maxn];
bool visited[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
struct step {
	int x, y;
	string path;
	step(int _x = 0, int _y = 0, const string& _path = "")
		: x(_x), y(_y), path(_path) {}
};
step ans;

bool bfs() {
	queue<step> qs;
	qs.push(step());
	visited[0][0] = true;
	while (!qs.empty()) {
		step cur = qs.front();
		qs.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = dx[i] + cur.x;
			int ny = dy[i] + cur.y;
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
			if (visited[nx][ny]) continue;
			if (maze[nx][ny] == 1) continue;
			if (nx == 4 && ny == 4) {
				ans = step(nx, ny, cur.path + char('0' + i));
				return true;
			}
			visited[nx][ny] = true;
			qs.push(step(nx, ny, cur.path + char('0' + i)));
		}
	}
	return false;
}

int main(void) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> maze[i][j];
		}
	}
	if(bfs()) {
		int x = 0, y = 0;
		cout << "(" << x << ", " << y << ")" << endl;
		for (int i = 0; i < ans.path.length(); i++) {
			int k = ans.path[i] - '0';
			x += dx[k];
			y += dy[k];
			cout << "(" << x << ", " << y << ")" << endl;
		}
	}
	
	return 0;
}
