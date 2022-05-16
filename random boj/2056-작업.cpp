#include <bits/stdc++.h>
using namespace std;

int n, m, a;
vector<int> w, ind, dp;
vector<vector<int>> v;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 
    w.resize(n + 1); v.resize(n + 1); ind.resize(n + 1); dp.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> m; ind[i] = m;
        for (int j = 1; j <= m; j++) {
            cin >> a; v[a].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            q.push(i); dp[i] = w[i];
        }
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i: v[t]) {
            dp[i] = max(dp[i], dp[t] + w[i]);
            ind[i]--;
            if (!ind[i]) q.push(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout << ans << '\n';

    return 0;
}