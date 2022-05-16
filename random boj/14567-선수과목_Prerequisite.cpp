#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> dp, ind;
vector<vector<int>> v;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    v.resize(n + 1); dp.resize(n + 1); ind.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b); ind[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) {
            dp[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        int t = q.front();
        q.pop();

        for (int i: v[t]) {
            dp[i] = max(dp[i], dp[t] + 1);
            ind[i]--;
            if (!ind[i]) q.push(i);
        }
    }

    for (int i = 1; i <= n; i++) cout << dp[i] << " ";

    return 0;
}