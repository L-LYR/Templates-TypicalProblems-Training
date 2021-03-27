#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct interval
{
    int len, due;
    interval(int _len = 0, int _due = 0) { len = _len, due = _due; };
    bool friend operator<(const interval &a, const interval &b) { return a.len < b.len; };
};
bool cmp(const interval &a, const interval &b)
{
    return a.due < b.due;
}
const int maxn = 800005;
interval arr[maxn];
int main(void)
{
    int n;
    cin >> n;

    // auto cmp = [](const interval &a, const interval &b) -> bool { return a.due > b.due; };
    // priority_queue<interval, vector<interval>, decltype(cmp)> q(cmp);
    priority_queue<interval> q;

    for (int i = 0; i < n; ++i)
        cin >> arr[i].len >> arr[i].due;

    sort(arr, arr + n, cmp); //sort by due times

    int curTime = 0;

    for (int i = 0; i < n; ++i)
    {
        q.push(arr[i]);              //receive requests one by one
        curTime += arr[i].len;       //increase curTime
        while (curTime > arr[i].due) //if exceeding the current request's due time, we will minus the biggest request
        {
            interval temp = q.top();
            curTime -= temp.len;
            q.pop();
        }
    }
    cout << q.size() << endl;
    return 0;
}