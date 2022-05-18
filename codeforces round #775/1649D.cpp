#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> v;
bool ck[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; 

    while (t--) {
        cin >> n >> m; int mx = 0;
        v.resize(n); bool ok = true;
        for (int i = 1; i <= m; i++) ck[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i]; mx = max(mx, v[i]); ck[v[i]] = true;
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (int i = 1; i <= m; i++) {
            if (ck[i]) continue;

            for (int j = 1; j <= m / i; j++) {
                if (!ck[j]) continue;
                int p = lower_bound(v.begin(), v.end(), j * i) - v.begin();
                if (p == v.size()) continue;
                else if (v[p] / j == i) { ok = false; break; }
            }

            if (!ok) break;
        }

        if (ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';

        v.clear();
    }

    return 0;
}