#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, m, a, b, c;
vector<vector<int>> v;
vector<ll> cnt, dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1); cnt.resize(n + 1); dp.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> cnt[i];

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;

        for (int j = 0; j < b; j++) {
            cin >> c; v[a].push_back(c);
        }
    }

    int low = 0; int high = 1e9;

    while (low + 1 < high) {
        int mid = (low + high) / 2;

        for (ll& i: dp) i = 0;

        dp[n] = mid;
        bool ok = true;

        for (int i = n; i; i--) {
            dp[i] = max(dp[i] - cnt[i], (ll)0);
            if (!dp[i]) continue;
            else {
                if (dp[i] > (i - 1) * 1e4) ok = false;
                if (!v[i].size()) ok = false;
            }

            for (int j: v[i]) dp[j] += dp[i];
        }

        if (ok) low = mid;
        else high = mid;
    }

    cout << low << '\n';

    return 0;
}