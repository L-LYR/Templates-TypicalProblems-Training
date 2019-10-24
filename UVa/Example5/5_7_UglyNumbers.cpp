#include <iostream>
#include <cstdint>
#include <set>
using namespace std;
int main(void)
{
    set<uint64_t> ugly_num;
    ugly_num.insert(1);
    set<uint64_t>::iterator it = ugly_num.begin();
    int count = 0;
    while (++count != 1500)
    {
        ugly_num.insert((*it) * 2);
        ugly_num.insert((*it) * 3);
        ugly_num.insert((*it) * 5);
        ++it;
    }
    cout << "The 1500'th ugly number is " << *it << "." << endl;
    return 0;
}