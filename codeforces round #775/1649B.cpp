#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; ll s = 0;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++) s += v[i];

        ll tmp = v[n-1] - s;

        if (s == 0 && v[n-1] == 0) { cout << 0 << '\n'; continue; }

        if (tmp <= 1) cout << 1 << '\n';
        else cout << tmp << '\n';

        v.clear();
    }

    return 0;
}