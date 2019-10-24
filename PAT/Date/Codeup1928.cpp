#include <iostream>
using namespace std;
int main(void)
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a > b)
            swap(a, b);
        
    }
    return 0;
}