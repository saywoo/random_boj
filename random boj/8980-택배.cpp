#include <bits/stdc++.h>
using namespace std;

struct q
{
    int s, e, n;
    bool operator<(q a) {
        if (a.e == e) return s < a.s;
        else return e < a.e;
    }
};

int n, c, m;
vector<q> v;
vector<int> memo;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> c >> m;
    v.resize(m); memo.resize(n + 1, 0);
    for (int i = 0; i < m; i++) cin >> v[i].s >> v[i].e >> v[i].n;
    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int tmp = v[i].n;
        for (int j = v[i].s; j < v[i].e; j++) tmp = min(c - memo[j], tmp);
        ans += tmp;
        for (int j = v[i].s; j < v[i].e; j++) memo[j] += tmp;
    }

    cout << ans << '\n';
    return 0;
}