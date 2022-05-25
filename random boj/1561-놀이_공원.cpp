#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll low = 0; ll high = 1e12;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        ll tmp = 0;
        for (int i = 0; i < n; i++) tmp += (mid + v[i] - 1) / v[i];

        if (tmp >= m) high = mid;
        else low = mid;
    }

    ll tmp = 0;
    for (int i = 0; i < n; i++) tmp += (low + v[i] - 1) / v[i];

    // cout << tmp << '\n';
    tmp = m - tmp; ll c = 0;

    for (int i = 0; i < n; i++) {
        if ((low + v[i]) % v[i] == 0) c++;
        if (c == tmp) { cout << i + 1 << '\n'; break; } 
    }

    return 0;
}