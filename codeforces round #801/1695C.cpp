#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<vector<ll>> v, a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; ll ans = 0;
        v.resize(n + 1); a.resize(n + 1); b.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            v[i].resize(m + 1); a[i].resize(m + 1); b[i].resize(m + 1); 
            for (int j = 1; j <= m; j++) {
                cin >> v[i][j];
                if (i != 1) {
                    a[i][j] = a[i-1][j]; b[i][j] = b[i-1][j];
                }
                if (j != 1) {
                    a[i][j] = max(a[i][j], a[i][j-1]);
                    b[i][j] = max(b[i][j], b[i][j-1]);
                }
                if (v[i][j] == 1) a[i][j]++;
                else b[i][j]++;
            }
        }

        ans = (n + m - 1);

        if (a[n][m] >= ans / 2 && b[n][m] >= ans / 2 && ans % 2 == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        v.clear(); a.clear(); b.clear();
    }

    return 0;
}