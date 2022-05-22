#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> v, dp, rdp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    dp.resize(n + 1, 1); rdp.resize(n + 1); v.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j; j--) {
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    rdp = dp;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j; j--) {
            if (v[j] > v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++) ans = max(dp[i], ans);

    cout << ans << '\n';

    return 0;
}