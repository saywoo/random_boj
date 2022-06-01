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
    n--;

    for (ll i = 2; v <= m; i++) {
        ll tmp = i * v / __gcd(i, v);
        ans += (m / v - n / v) * (dp[i] + 1);
        v = tmp;
        ans -= (m / v - n / v) * (dp[i] + 1);
    }

    cout << ans << '\n';

    return 0;
}