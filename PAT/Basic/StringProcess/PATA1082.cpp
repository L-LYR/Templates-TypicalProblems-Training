#include <iostream>
#include <string>
#include <vector>

using namespace std;
string digits[] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu",
};

void qian(int i, vector<string> &ans)
{
    int nums[] = {
        i / 1000,
        i % 1000 / 100,
        i % 100 / 10,
        i % 10,
    };

    if (nums[0] != 0)
    {
        ans.push_back(digits[nums[0]]);
        ans.push_back("Qian");
    }

    if (nums[1] != 0)
    {
        ans.push_back(digits[nums[1]]);
        ans.push_back("Bai");
    }
    else if (nums[1] == 0 && nums[0] != 0 && (nums[2] != 0 || nums[3] != 0))
        ans.push_back("ling");

    if (nums[2] != 0)
    {
        ans.push_back(digits[nums[2]]);
        ans.push_back("Shi");
    }
    else if (nums[2] == 0 && nums[1] != 0 && nums[3] != 0)
        ans.push_back("ling");

    if (nums[3] != 0)
        ans.push_back(digits[nums[3]]);
}

int main(void)
{
    int num;
    cin >> num;
    if (num == 0)
    {
        cout << "ling" << endl;
        return 0;
    }
    vector<string> ans;
    if (num < 0)
    {
        ans.push_back("Fu");
        num = -num;
    }

    int part[] = {
        num / 100000000,
        num % 100000000 / 10000,
        num % 10000,
    };

    if (part[0] > 0)
    {
        ans.push_back(digits[part[0]]);
        ans.push_back("Yi");
    }

    if (part[1] < 1000 && part[0] > 0)
        ans.push_back("ling");

    qian(part[1], ans);

    if (part[1] > 0)
        ans.push_back("Wan");

    if (part[2] < 1000 && part[1] > 0)
        ans.push_back("ling");

    qian(part[2], ans);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}