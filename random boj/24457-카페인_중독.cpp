#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, ans = 0;
vector<pr> v;
vector<vector<pr>> dp;

bool cmp(pr x, pr y)
{
    if (x.B == y.B) return x.A > y.A;
    else return x.B < y.B;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n); dp.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i].A;
    for (int i = 0; i < n; i++) cin >> v[i].B;

    sort(v.begin(), v.end(), cmp);

    for (int i = n; i >= 0; i--) {
        dp[i].resize(n + 1);
        dp[i][0] = {0, 0};
        for (int j = 1; j <= n - i; j++) {
            pr rep = { dp[i+1][j-1].A + 1, max(dp[i+1][j-1].B - dp[i+1][j-1].A * v[i].B + v[i].A, (ll)0) };
            if (cmp(dp[i+1][j], rep)) dp[i][j] = rep;
            else dp[i][j] = dp[i+1][j];
        }    
    }

    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[0][i].B);
    }

    cout << ans << '\n';

    return 0;
}