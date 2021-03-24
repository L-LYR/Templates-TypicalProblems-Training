#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;
const int maxn = 1e4 + 5;
bool is_prime[maxn];

void get_prime() {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < maxn; ++i) is_prime[i] = true;
	for (int i = 2; i < maxn; ++i) {
		if (is_prime[i] && i * i < maxn) {
			for (int j = i * i; j < maxn; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

string s;
int t;
char digits[] = "0123456789";
bool visited[maxn];

int stoi(const string& s) {
	int ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		ans = ans * 10 + (s[i] - '0');
	}
	return ans;
}
typedef pair<int, int> pii;
int bfs() {
	queue<pii> iq;
	iq.push(make_pair(stoi(s), 0));
	
	while (!iq.empty()) {
		pii cur = iq.front();
		iq.pop();
		if (cur.first == t) return cur.second;
		// cout << cur.first << endl;
		char tmp[4];
		sprintf(tmp, "%d", cur.first);
		string cs(tmp);
		for (int j = 0; j < 4; ++j) {
			char c = cs[j];
			int i = 0;
			if (j == 0) i = 1;
			for (; i < 10; ++i) {
				if (digits[i] == c) continue;
				cs[j] = digits[i];
				int ci = stoi(cs);
				if (is_prime[ci] && !visited[ci]) {
					visited[ci] = true;
					iq.push(make_pair(ci, cur.second + 1));
				}
			}
			cs[j] = c;
		}	
	}
	return -1;
}

int main(void) {
	get_prime();

	int n;
	cin >> n;
	while (n-- > 0) {
		cin >> s >> t;
		memset(visited, false, sizeof(visited));
		cout << bfs() << endl;
	}

	return 0;
}
