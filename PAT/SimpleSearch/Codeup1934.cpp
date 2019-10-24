// #include <vector>
#include <map>
#include <iostream>
using namespace std;
int main(void)
{
    int n;
    while (cin >> n)
    {
        // vector<int> arr;
        map<int, int> arr;
        int temp, x;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            // arr.push_back(temp);
            arr.insert(make_pair(temp, i));
        }
        cin >> x;
        // bool flag = true;
        // for (int i = 0; i < arr.size(); ++i)
        //     if (arr[i] == x)
        //     {
        //         cout << i << endl;
        //         flag = false;
        //     }
        // if (flag)
        //     cout << -1 << endl;
        if (arr.count(x))
            cout << arr[x] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}