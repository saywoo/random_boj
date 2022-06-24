#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int t, n, m;
vector<vector<ll>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; v.resize(n); int x, y, mx = -1000000001;
        for (int i = 0; i < n; i++) {
            v[i].resize(m);
            for ( int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (mx < v[i][j]) {
                    x = i; y = j;
                    mx = v[i][j];
                }
            }
        }

        int c = max(x, n - x - 1);
        int d = max(y, m - y - 1);

        cout << (c + 1) * (d + 1) << '\n';

        v.clear(); 
    }

    return 0;
}