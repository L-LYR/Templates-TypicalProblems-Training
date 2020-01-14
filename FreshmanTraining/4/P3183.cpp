#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &map, int k, vector<int> &memo)
{
    if (memo[k] != 0) //have reached before
        return memo[k];
    if (map[k].empty()) //end
        return 1;
    for (auto i : map[k]) //each destinations
        memo[k] += dfs(map, i, memo);
    return memo[k]; //total
}

int main(void)
{
    int n, m, num;
    cin >> n >> m;
    vector<vector<int>> map(n + 1);
    vector<int> degree(n + 1, 0); //in-degree
    vector<int> memo(n + 1, 0);   //memory
    int s, e;
    for (int i = 0; i < m; ++i)
    {
        cin >> s >> e;
        map[s].push_back(e);
        degree[e]++;
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0 && !map[i].empty())
            num += dfs(map, i, memo);
    cout << num << endl;
    return 0;
}