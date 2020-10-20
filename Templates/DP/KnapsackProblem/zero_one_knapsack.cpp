#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int c[maxn], v[maxn];  // cost & value
int V, n;              // Volume & number

int dp_2d[maxn][maxn];
int dp_1d[maxn];
void init() {
    // Initialize all the dp array to 0
    // to get the maximum value solution.
    memset(dp_2d, 0, sizeof(dp_2d));
    memset(dp_1d, 0, sizeof(dp_1d));
    // Initialize dp[0] to 0 but the others to -INF.
    // This kind of initialization can make knapsack
    // fullfilled exactly.
    // memset(dp_2d, 0x3F, sizeof(dp_2d));
    // dp_2d[0][0] = 0;
    // memset(dp_1d, 0x3F, sizeof(dp_1d));
    // dp_1d[0] = 0;
}

void zero_one_knapsack_2d() {
    for (int i = 1; i <= n; ++i) {                                 // for each item i [1->n]
        for (int j = 0; j <= V; ++j) {                             // pay attention to the inner loop [0->V]
            if (j >= c[i]) {                                       // choose the greater one
                dp_2d[i][j] = max(dp_2d[i - 1][j],                 // not pick up the item i
                                  dp_2d[i - 1][j - c[i]] + v[i]);  // pick up the item i
            } else {                                               // cannot pick up the item i
                dp_2d[i][j] = dp_2d[i - 1][j];
            }
        }
    }
}

void zero_one_knapsack_1d() {
    for (int i = 1; i <= n; ++i) {         // [1->n]
        for (int j = V; j >= c[i]; --j) {  // [V->c[i]]
            dp_1d[j] = max(dp_1d[j],
                           dp_1d[j - c[i]] + v[i]);
        }
    }
}

// Template Problem:
// HDU 2602

int main(void) {
    cin >> n >> V;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    init();
    zero_one_knapsack_2d();
    zero_one_knapsack_1d();

    cout << dp_2d[n][V] << endl;
    cout << dp_1d[V] << endl;

    return 0;
}