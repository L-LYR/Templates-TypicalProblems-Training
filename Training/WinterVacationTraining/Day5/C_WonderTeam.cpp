#include <iostream>
#include <map>

using namespace std;
// each team has 2n-2 competitions
// wonder team
// 1. only win 2 competitions by inf : 0
// 2. lose for n - 1 times by 0 : 1 (So there exist two certain teams)
// 3. draw n - 3 times
// score n + 3
//
// two teams
// 1. win 0
// 2. lose 1
// 3. draw 2n-3
// score 2n-3
//
// other teams
// 1. win 1
// 2. lose 0
// 3. draw 2n-3
// score 2n

// n + 3 > 2n => n < 3
// n + 3 > 2n - 3 => n < 6

int main(void)
{
	int n;
	while (cin >> n && n != 0)
	{
		if (n <= 3)
			cout << 1;
		else if (n == 4)
			cout << 2;
		else
			cout << n;
		cout << endl;
	}

	return 0;
}