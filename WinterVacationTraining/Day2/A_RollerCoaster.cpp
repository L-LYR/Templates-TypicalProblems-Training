#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n, gn, bn; // edge number, girl number, boy number
const int maxn = 505;
bool relation[maxn][maxn]; // girl-boy
int gm[maxn], bm[maxn];	   // girl match, boy match
bool visit[maxn];

int extend_path(int i)
{
	for (int j = 1; j <= bn; ++j)
	{
		if (relation[i][j] && !visit[j])
		{
			visit[j] = true;

			if (bm[j] == -1 || extend_path(bm[j]))
			{
				bm[j] = i;
				gm[i] = j;
				return 1;
			}
		}
	}
	return 0;
}

int max_match(void)
{
	memset(gm, -1, sizeof(gm)); // no match for each set
	memset(bm, -1, sizeof(bm));
	int ans = 0;

	for (int i = 1; i <= gn; ++i)
	{
		if (gm[i] == -1)
		{
			memset(visit, 0, sizeof(visit));
			ans += extend_path(i);
		}
	}
	return ans;
}

int main(void)
{
	while (cin >> n && n != 0)
	{
		cin >> gn >> bn;
		memset(relation, 0, sizeof(relation));
		memset(visit, 0, sizeof(visit));
		int g, b;
		for (int i = 0; i < n; ++i)
		{
			cin >> g >> b;
			relation[g][b] = true;
		}
		cout << max_match() << endl;
	}
	return 0;
}