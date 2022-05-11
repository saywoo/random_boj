#include <bits/stdc++.h>
using namespace std;

int t, n, m, q;
vector<int> v, ps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;
        v.resize(n); ps.resize(n + 1);
        for (int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < n; i++) ps[i+1] = ps[i] + v[i];

        for (int i = 0; i < m; i++) {
            cin >> q;

            int pos = lower_bound(ps.begin(), ps.end(), q) - ps.begin();
            if (pos > n) cout << -1 << '\n';
            else cout << pos << '\n';
        }
    }

    return 0;
}