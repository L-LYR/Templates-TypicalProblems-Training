#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int N;
    while (cin >> N && N != 0)
    {
        vector<int> arr(101, 0);
        int mark;
        while (--N >= 0)
        {

            cin >> mark;
            arr[mark]++;
        }
        cin >> mark;
        cout << arr[mark] << endl;
    }
    return 0;
}