#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, m, mx = 0, s = 0;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; s += v[i];
        int c = i + 1;

        mx = max((s - 1) / c, mx);
    }

    cin >> q;
    while (q--) {
        cin >> m;

        if (m <= mx) cout << -1 << '\n';
        else cout << ((s + m - 1) / m) << '\n';
    }

    return 0;
}