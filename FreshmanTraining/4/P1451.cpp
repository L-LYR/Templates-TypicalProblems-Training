#include <iostream>
#include <queue>
using namespace std;
const int maxn = 105;
char cell[maxn][maxn];
bool visited[maxn][maxn];
int cnt, n, m;
int d[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

#define inCol(c) (c >= 0 && c < m)
#define inRow(r) (r >= 0 && r < n)

void bfs(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({r, c});
	while (!q.empty())
	{
		int ql = q.size();
		for (int i = 0; i < ql; ++i)
		{
			auto s = q.front();
			q.pop();
			r = s.first;
			c = s.second;
			visited[r][c] = true;
			if (cell[r][c] != '0')
			{
				for (int j = 0; j < 4; ++j)
					if (inRow(r + d[j][0]) && inCol(c + d[j][1]) && !visited[r + d[j][0]][c + d[j][1]])
						q.push({r + d[j][0], c + d[j][1]});
			}
		}
	}
}
int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		scanf("%s", cell[i]);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j])
			{
				if (cell[i][j] != '0')
				{
					bfs(i, j);
					++cnt;
				}
				visited[i][j] = true;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
