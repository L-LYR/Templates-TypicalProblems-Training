#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int maxn = 105;

const char *opt[] = {
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)",
};

int a, b, c;
bool visited[maxn][maxn];
struct node {
	int l, r;
	int step;
	string s; // Use a string to save the path
			  // This can be replaced by a char array, too.
	node(int _l = 0, int _r = 0, int _step = 0, const string& _s = "")
		: l(_l), r(_r), step(_step), s(_s) {}
};

bool bfs() {
	queue<node> qn;
	qn.push(node());
	visited[0][0] = true;
	while (!qn.empty()) {
		node cur = qn.front();
		qn.pop();
		if (cur.l == c || cur.r == c) {
			cout << cur.step << endl;
			for (int i = 0; i < cur.s.length(); ++i) {
				cout << opt[cur.s[i] - '0'] << endl;
			}
			return true;
		}
		if (cur.l < a && !visited[a][cur.r]) {
			visited[a][cur.r] = true;
			qn.push(node(a, cur.r, cur.step + 1, cur.s + '0'));
		}
		if (cur.r < b && !visited[cur.l][b]) {
			visited[cur.l][b] = true;
			qn.push(node(cur.l, b, cur.step + 1, cur.s + '1'));
		}
		if (cur.l > 0 && !visited[0][cur.r]) {
			visited[0][cur.r] = true;
			qn.push(node(0, cur.r, cur.step + 1, cur.s + '2'));
		}
		if (cur.r > 0 && !visited[cur.l][0]) {
			visited[cur.l][0] = true;
			qn.push(node(cur.l, 0, cur.step + 1, cur.s + '3'));
		}
		if (cur.l > 0 && cur.r < b) {
			int cl = max(cur.l + cur.r - b, 0);
			int cr = min(cur.r + cur.l, b);
			if (!visited[cl][cr]) {
				visited[cl][cr] = true;
				qn.push(node(cl, cr, cur.step + 1, cur.s + '4'));
			}
		}
		if (cur.l < a && cur.r >0) {
			int cl = min(cur.r + cur.l, a);
			int cr = max(cur.r + cur.l - a, 0);
			if (!visited[cl][cr]) {
				visited[cl][cr] = true;
				qn.push(node(cl, cr, cur.step + 1, cur.s + '5'));
			}
		}	
	}
	return false;
}


int main(void) {
	cin >> a >> b >> c;
	if (!bfs()) {
		cout << "impossible" << endl;
	}
	return 0;
}
