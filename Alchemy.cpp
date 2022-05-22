#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<int> cnt, ind, dp;
vector<vector<int>> v;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 
    cnt.resize(n + 1); ind.resize(n + 1); v.resize(n + 1); dp.resize(n + 1, 1e9);
    for (int i = 1; i <= n; i++) cin >> cnt[i];

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b; ind[a] = b;
        for (int j = 0; j < b; j++) {
            cin >> c; v[c].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        if (dp[t] != 1e9) cnt[t] += dp[t];

        if (t == n) { cout << cnt[n] << '\n'; break; }

        for (int i: v[t]) {
            dp[i] = min(dp[i], cnt[t]);
            ind[i]--;
            if (!ind[i]) q.push(i);
        }
    }

    return 0;
}