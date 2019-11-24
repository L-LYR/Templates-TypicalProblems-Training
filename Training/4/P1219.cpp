#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 15, maxNum = 3;

int cnt, n;
int ans[maxn];

bool check(int r, int c)
{
	//for the same col
	for (int i = 1; i <= n; ++i)
		if (ans[i] == c)
			return false;
	//for the diagonals
	for (int i = 1; i < r; ++i)
		if (abs(i - r) == abs(ans[i] - c))
			return false;
	return true;
}

void dfs(int r)
{
	if (r == n + 1)
	{
		++cnt;
		if (cnt <= maxNum)
		{
			for (int i = 1; i < n; ++i)
				cout << ans[i] << " ";
			cout << ans[n] << endl;
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (check(r, i))
			{
				ans[r] = i;
				dfs(r + 1);
				ans[r] = -1;
			}
		}
	}
}

int main(void)
{
	cin >> n;
	dfs(1);
	cout << cnt << endl;
	return 0;
}
