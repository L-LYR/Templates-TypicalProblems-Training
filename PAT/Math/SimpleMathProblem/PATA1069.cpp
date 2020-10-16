#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

inline int get_val(int nums[4]) {
    return nums[0] * 1000 + nums[1] * 100 + nums[2] * 10 + nums[3];
}

inline void get_val(int nums[4], int number) {
    nums[3] = number % 10;
    nums[2] = number / 10 % 10;
    nums[1] = number / 100 % 10;
    nums[0] = number / 1000;
}

int main(void) {
    int nums[4], n;
    cin >> n;
    get_val(nums, n);
    int mi, ma, su = -1;
    while (su != 6174 && su != 0) {
        sort(nums, nums + 4, less<int>());
        mi = get_val(nums);
        sort(nums, nums + 4, greater<int>());
        ma = get_val(nums);
        su = ma - mi;
        printf("%04d - %04d = %04d\n", ma, mi, su);
        get_val(nums, su);
    }

    return 0;
}