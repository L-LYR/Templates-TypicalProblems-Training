#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int nums[4][4];
string ans[3];
int flag;
string ops[] = {"+", "-", "*", "/"};

void dfs(int k)
{
	if (k == 0)
	{
		if (nums[0][0] == 24)
		{
			flag = 1;
			return;
		}
	}
	else
	{
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (j == 0)
					nums[k - 1][i - 1] = nums[k][i - 1] + nums[k][i];
				else if (j == 1)
					nums[k - 1][i - 1] = max(nums[k][i - 1], nums[k][i]) - min(nums[k][i - 1], nums[k][i]);
				else if (j == 2)
					nums[k - 1][i - 1] = nums[k][i - 1] * nums[k][i];
				else if (j == 3 && nums[k][i] != 0 && nums[k][i - 1] % nums[k][i] == 0)
					nums[k - 1][i - 1] = nums[k][i - 1] / nums[k][i];
				else
					break;

				if (i == 1)
				{
					nums[k - 1][1] = nums[k][2];
					nums[k - 1][2] = nums[k][3];
				}
				else if (i == 2)
				{
					nums[k - 1][0] = nums[k][0];
					nums[k - 1][2] = nums[k][3];
				}
				else if (i == 3)
				{
					nums[k - 1][0] = nums[k][0];
					nums[k - 1][1] = nums[k][1];
				}

				dfs(k - 1);

				if (flag)
				{
					ans[3 - k] = to_string(max(nums[k][i], nums[k][i - 1])) +
								 ops[j] +
								 to_string(min(nums[k][i], nums[k][i - 1])) +
								 "=" +
								 to_string(nums[k - 1][i - 1]);
					return;
				}
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 4; ++i)
		cin >> nums[3][i];

	do
	{
		dfs(3);
	} while (next_permutation(nums[3], nums[3] + 4) && flag == 0);

	if (flag)
	{
		for (int i = 0; i < 3; ++i)
			cout << ans[i] << endl;
	}
	else
		cout << "No answer!" << endl;
	return 0;
}
