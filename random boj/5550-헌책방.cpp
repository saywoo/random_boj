#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
vector<vector<ll>> v, ps, dp;
bool ok[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(11); ps.resize(11); dp.resize(11);
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b; ok[b] = true;
        v[b].push_back(a);
    }

    for (int i = 1; i <= 10; i++) {
        v[i].push_back(1e9); ps[i].resize(v[i].size());
        sort(v[i].begin(), v[i].end(), greater<>());

        for (int j = 1; j < v[i].size(); j++) ps[i][j] = v[i][j] + ps[i][j-1] + (j - 1) * 2;
    }

    for (int i = 0; i <= 10; i++) dp[i].resize(m + 1);

    for (int i = 1; i <= 10; i++) {
        if (!ok[i]) {
            for (int j = 0; j <= m; j++) dp[i][j] = dp[i-1][j];
            continue;
        }

        for (int j = 0; j <= m; j++) {
            for (int k = 0; j + k <= m && k < ps[i].size(); k++) dp[i][j+k] = max(dp[i][j+k], dp[i-1][j] + ps[i][k]);
        }
    }

    cout << dp[10][m] << '\n';

    return 0;
}