#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, m, t;
vector<vector<int>> v;
vector<ll> x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; ll ans = 0;
        
        v.resize(n); x.resize(n + m + 1, 0); y.resize((n + m) * 3, 0);
        for (int i = 0; i < n; i++) {
            v[i].resize(m);
            for (int j = 0; j < m; j++) cin >> v[i][j];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                x[i+j] += v[i][j];
                y[i-j+n+m] += v[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) ans = max(ans, x[i+j] + y[i-j+n+m] - v[i][j]);
        }


        cout << ans << '\n';

        x.clear(); y.clear(); v.clear();
    }

    return 0;
}