#include <bits/stdc++.h>
using namespace std;


void NextPermutation(vector<int>& nums) {
	if (nums.empty() || nums.size() == 1) return;
	int k = nums.size() - 1;
	int j = k - 1;
	while (j >= 0 && nums[j] >= nums[j + 1]) j--;
	if (j >= 0) {
		while (k >= 0 && nums[j] >= nums[k]) k--;
		swap(nums[j], nums[k]);
	}
	reverse(nums.begin() + j + 1, nums.end());
}


int main(void) {
	vector<int> nums = {1, 3, 5, 6, 3};
	for (auto i: nums) cout << i;
	cout << endl;
	NextPermutation(nums);
	for (auto i: nums) cout << i;
	cout << endl;
	return 0;
}
