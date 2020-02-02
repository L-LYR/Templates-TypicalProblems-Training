#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 300005;
struct flight
{
	int c, i;
	friend bool operator<(flight f1, flight f2)
	{
		if (f1.c < f2.c)
			return true;
		else if (f1.c > f2.c)
			return false;
		else
			return f1.i < f2.i;
	}
};

flight f[maxn];
int t[maxn];
int main(void)
{
	int n, k, c;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c;
		f[i] = {c, i};
	}
	long long cost = 0;
	priority_queue<flight> schedule;
	for (int i = 1; i <= k; ++i)
		schedule.push(f[i]);
	for (int i = k + 1; i <= k + n; ++i)
	{
		if (i <= n)
			schedule.push(f[i]);
		auto cur = schedule.top();
		schedule.pop();
		t[cur.i] = i;
		cost += cur.c * (long long)(i - cur.i);
	}
	cout << cost << endl;
	for (int i = 1; i <= n; ++i)
		cout << t[i] << " ";
	cout << endl;
	return 0;
}