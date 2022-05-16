#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, a, b, p_cnt = 0, cnt = 0, mid, high = 0;
vector<ll> w, dp;
vector<vector<ll>> v;

void dfs(int p)
{
    dp[p] = -1; ll mx = 1;

    for (int i: v[p]) {
        if (w[i] <= mid) {
            if (dp[i] == -1) mx = 1e18;
            if (!dp[i]) dfs(i);
            mx = max(mx, dp[i] + 1);
        }
    }

    dp[p] = mx;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    w.resize(n + 1); v.resize(n + 1); dp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; high = max(w[i], high);
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
    }

    ll low = 0; high++; ll ans = -1;

    while (low + 1 < high) {
        mid = (low + high) / 2; bool ok = false;
        for (int i = 1; i <= n; i++) dp[i] = 0;

        for (int i = 1; i <= n; i++) {
            if (w[i] <= mid && !dp[i]) dfs(i);
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] >= k) ok = true;
        }

        if (ok) { ans = mid; high = mid; }
        else low = mid;
    }

    cout << ans << '\n';

    return 0;
}