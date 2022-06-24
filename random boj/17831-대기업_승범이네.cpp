#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> dp[2], cost;
vector<vector<int>> v;

void dfs(int p)
{
    for (int i: v[p]) {
        dfs(i);
        dp[0][p] += max(dp[1][i], dp[0][i]);
    }

    for (int i: v[p]) dp[1][p] = max(dp[1][p], dp[0][p] - max(dp[0][i], dp[1][i]) + (cost[i] * cost[p]) + dp[0][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cost.resize(n + 1); dp[0].resize(n + 1); dp[1].resize(n + 1); v.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> m;
        v[m].push_back(i);
    }

    for (int i = 1; i <= n; i++) cin >> cost[i];

    dfs(1);

    cout << max(dp[1][1], dp[0][1]) << '\n';

    return 0;
}