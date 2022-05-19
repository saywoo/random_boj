#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
vector<vector<ll>> v;
vector<ll> w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m;
        v.resize(n); w.resize(n); bool ok = true; int s = 1; int e = 1; int cnt = 1;
        for (int i = 0; i < n; i++) {
            v[i].resize(m);
            for (int j = 0; j < m; j++) cin >> v[i][j];
        }
        bool f = false;

        for (int i = m - 1; i; i--) {
            bool flag = true;

            for (int j = 0; j < n; j++) {
                if (v[j][i] < v[j][i-1]) {
                    flag = false; break;
                }
            }

            if (!flag) {
                e = i + 1;

                if (i == 1) {
                    s = 1;
                    for (int j = 0; j < n; j++) swap(v[j][1], v[j][0]);
                    f = true;
                    break;
                }

                for (int j = i - 2; j >= 0; j--) {
                    for (int k = 0; k < n; k++) {
                        if (v[k][j] > v[k][j+1]) {
                            f = true; s = j + 1;

                            for (int l = 0; l < n; l++) swap(v[l][s-1], v[l][e-1]); 
                            break;
                        } 
                    }
                    if (f) break;
                }
            }

            if (f) break;
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (v[j][i] > v[j][i+1]) { ok = false; break; }
            }
            if (!ok) break;
        }


        if (!ok) cout << -1 << '\n';
        else cout << s << " " << e << '\n';
        v.clear(); w.clear();
    }

    return 0;
}