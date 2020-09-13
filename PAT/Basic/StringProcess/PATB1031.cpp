#include <iostream>
#include <string>
#include <vector>
using namespace std;
int w[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = "10X98765432";

int main(void)
{
    int n;
    cin >> n;
    string temp;
    vector<string> id;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        int z = 0, flag = 1;
        for (int j = 0; j < 17; ++j)
        {
            if (isdigit(temp[j]))
                z += (temp[j] - '0') * w[j];
            else
            {
                flag = 0;
                break;
            }
        }
        if (!flag || temp[17] != m[z % 11])
            id.push_back(temp);
    }
    if (id.empty())
        cout << "All passed" << endl;
    else
        for (auto i : id)
            cout << i << endl;
}
