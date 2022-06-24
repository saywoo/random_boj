#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, ans = 0;
vector<ll> a, b, x, y;

void solve(vector<ll> &l, vector<ll> &p)
{
    int pp = 0;
    l.push_back(-1e9); l.push_back(1e9);
    sort(l.begin(), l.end()); sort(p.begin(), p.end());

    for (int i = 1; i < l.size(); i++) {
        vector<ll> num, ps;
        while (pp < k && p[pp] <= l[i]) num.push_back(p[pp++]);

        if (num.size() == 0) continue;
        int siz = num.size();
        ll tmp = 0;
        for (int j = 0; j < siz; j++) {
            ps.push_back(num[j] + tmp);
            tmp = ps[j];
        }

        for (int j = 1; j < siz; j++) {
            int low = -1; int high = j;
            ll q = l[i] + l[i-1];

            while (low + 1 < high) {
                int mid = (low + high) / 2;
                if (num[mid] + num[j] < q) low = mid;
                else high = mid;
            }

            if (low == -1) ans += j * (l[i] - num[j]) * 2;
            else {
                ans += (ps[low] - (low + 1) * l[i-1]) * 2;
                ans += (j - low - 1) * (l[i] - num[j]) * 2;
            }
        }

        num.clear(); ps.clear();
    }

    ll s = 0;
    for (int i = 0; i < p.size(); i++) {
        ans += i * p[i] - s;
        s += p[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    a.resize(n); b.resize(m); x.resize(k); y.resize(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> x[i] >> y[i];

    solve(a, x); solve(b, y);

    cout << ans << '\n';

    return 0;
}
