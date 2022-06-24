#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        ll ans = 0;
        for (ll i = 1; i <= m; i++) ans += i;
        for (ll i = 2; i <= n; i++) ans += m * i;

        cout << ans << '\n';
    }

    return 0;
}