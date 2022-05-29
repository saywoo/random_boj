#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, tmp, ans = 0;
vector<ll> v, st, zp;
vector<vector<ll> > dp;

ll query(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 1e18;
    else if (s <= l && r <= e) return st[p];
    else return min(query(l, (l + r) / 2, s, e, p * 2), query((l + r) / 2 + 1, r, s, e, p * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; v.resize(n + 1); dp.resize(n + 1);
    for (tmp = 1; tmp < n; tmp *= 2) {}
    st.resize(tmp * 2);
    for (int i = 1; i <= n; i++) cin >> v[i];

    zp = v;
    sort(zp.begin(), zp.end());

    for (int i = 0; i <= n; i++) dp[i].resize(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = query(1, tmp, 1, j, 1) + abs(v[i] - zp[j]);
        for (int j = tmp; j < tmp + n; j++) st[j] = dp[i][j-tmp+1];
        for (int j = tmp - 1; j; j--) st[j] = min(st[j*2], st[j*2+1]);
    }

    ans = 1e18;
    for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);

    reverse(zp.begin() + 1, zp.end());

    for (int i = 0; i < st.size(); i++) st[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = query(1, tmp, 1, j, 1) + abs(v[i] - zp[j]);
        for (int j = tmp; j < tmp + n; j++) st[j] = dp[i][j-tmp+1];
        for (int j = tmp - 1; j; j--) st[j] = min(st[j*2], st[j*2+1]);
    }

    for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);

    cout << ans << '\n';
    return 0;
}
