#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, len;
    cin >> N;
    while (--N >= 0)
    {
        cin >> len;
        vector<int> arr(len), temp;
        for (int i = 1; i <= len; ++i)
            arr[i - 1] = i;
        for (int i = 0; arr.size() > 3; ++i)
        {
            int d = 2 + i % 2;
            for (int j = 1; j <= arr.size(); ++j)
                if (j % d)
                    temp.push_back(arr[j - 1]);
            arr.swap(temp);
            temp.clear();
        }
        for (auto i : arr)
            if (i == arr.front())
                cout << i;
            else
                cout << " " << i;
        cout << endl;
    }
    return 0;
}