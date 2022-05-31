#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, v = 1, ans = 0;
vector<ll> dp(46);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[2] = 1; 
    for (int i = 3; i <= 45; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j) { dp[i] = dp[j] + 1; break; }
        }
    }

    cin >> n >> m;

    ll x = n - 1; ll y = m;

    for (ll i = 2; v <= m; i++) {
        if (v % i == 0) continue;
        else {
            ll tmp = i;
            for (ll j = 2; j < i; j++) {
                if (tmp % j == 0) tmp /= j;
            }
            v *= tmp;
            ll a = x - (n - 1) / v; ll b = y - m / v;
            // cout << i << " " << v << " " << b - a << " " << dp[i] + 1 << '\n';
            ans += (b - a) * (dp[i] + 1);

            x = (n - 1) / v; y = m / v;
        }
    }

    cout << ans << '\n';

    return 0;
}