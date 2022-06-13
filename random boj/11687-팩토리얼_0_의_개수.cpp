#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    ll low = 0; ll high = 1e10;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        ll tmp = 0;

        for (ll i = 5; i <= mid; i *= 5) tmp += mid / i;

        if (tmp <= n) low = mid;
        else high = mid;
    }

    ans = low - 4;

    ll tmp = 0;
    for (ll i = 5; i <= ans; i *= 5) tmp += ans / i;

    if (n == tmp) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}