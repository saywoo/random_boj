#include <bits/stdc++.h>
using namespace std;

int n, sqn, q, a, b, c, d;
vector<int> v, g;
vector<vector<int>> num;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    sqn = 1500;
    v.resize(n + 1); g.resize(n + 1); num.resize(100);

    for (int i = 1; i <= n; i++) {
        cin >> v[i]; g[i] = i / sqn;
        num[g[i]].push_back(v[i]);
    }

    for (int i = 0; i < 100; i++) sort(num[i].begin(), num[i].end());

    cin >> q;

    while (q--) {
        cin >> a;

        if (a == 1) {
            cin >> b >> c;
            int p = g[b];

            for (int i = 0; i < num[p].size(); i++) {
                if (num[p][i] == v[b]) { num[p].erase(num[p].begin() + i); break; }
            }

            for (int i = 0; i <= num[p].size(); i++) {
                if (i == num[p].size()) { num[p].insert(num[p].begin() + i, c); break; }
                if (c <= num[p][i]) { num[p].insert(num[p].begin() + i, c); break; }
            }
            v[b] = c;
        }
        else {
            cin >> b >> c >> d;

            int cnt = 0;

            int s = g[b]; int e = g[c];

            for (int i = b; i <= n; i++) {
                if (s != g[i] || i > c) break;
                if (v[i] > d) cnt++;
            }

            for (int i = s + 1; i < e; i++) {
                cnt += num[i].end() - upper_bound(num[i].begin(), num[i].end(), d);
            }

            if (s != e) {
                for (int i = c; i; i--) {
                    if (e != g[i]) break;
                    if (v[i] > d) cnt++;
                }
            }

            cout << cnt << '\n';
        }
    }

    return 0;
}