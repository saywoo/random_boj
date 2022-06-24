#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
vector<ll> a, b;
vector<vector<ll>> dpa, dpb;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1); b.resize(m + 1);
    dpa.resize(n + 1); dpa[0].resize(m + 1, 1e18);
    dpb.resize(n + 1); dpb[0].resize(m + 1, 1e18);

    for (int i = 1; i <= n; i++) {
        dpa[i].resize(m + 1, 1e18);
        dpb[i].resize(m + 1, 1e18);
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) cin >> b[i];

    dpa[0][0] = 0; dpb[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll tmp = min(dpa[i-1][j-1], dpb[i-1][j-1]);
            dpa[i][j] = min(tmp + (a[i] - 1) * (b[j] - 1), dpa[i-1][j] + (a[i] - 1) * (b[j] - 1));
            dpb[i][j] = min(tmp + (a[i] - 1) * (b[j] - 1), dpb[i][j-1] + (a[i] - 1) * (b[j] - 1));
        }
    }
    
    cout << min(dpa[n][m], dpb[n][m]) << '\n';
    return 0;
}