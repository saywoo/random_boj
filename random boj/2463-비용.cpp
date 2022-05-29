#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
typedef long long int ll;
struct tri {
    ll a, b, c;

    bool operator<(const tri &rhs) const {
        return c < rhs.c;
    }
};
ll n, m, s, ans = 0;
vector<tri> v;
vector<ll> parent, siz;

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x); y = Find(y);
    if (x == y) return;
    parent[y] = x; siz[x] += siz[y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    v.resize(m); parent.resize(n + 1); siz.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i; siz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c; s += v[i].c;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        int x = Find(v[i].a); int y = Find(v[i].b);
        if (x != y) {
            ll p = siz[x] * siz[y];
            ans = (ans + s * p) % MOD;
            Union(v[i].a, v[i].b);
        }
        s -= v[i].c;
    }

    cout << ans << '\n';

    return 0;
}