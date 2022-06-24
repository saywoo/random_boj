#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<int, int> pr;
ll n, a, b, c, ans;
vector<vector<pr>> v;
vector<ll> dp, siz;
bitset<10000> visited;

void dfs(int p)
{
    visited[p] = true;
    siz[p] = 1; dp[p] = 0;

    for (auto i: v[p]) {
        if (!visited[i.A]) {
            dfs(i.A);
            siz[p] += siz[i.A];
            dp[p] += i.B * siz[i.A] + dp[i.A];
        }
    }
}

void exc(int p)
{
    visited[p] = true;
    ans = min(ans, dp[p]);

    for (auto i: v[p]) {
        if (!visited[i.A]) {
            dp[i.A] = dp[p] - i.B * siz[i.A] + i.B * (n - siz[i.A]);
            exc(i.A);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> n; ans = 1e12;
        if (!n) break; visited.reset();
        v.resize(n); dp.resize(n, 0); siz.resize(n);
        for (int i = 1; i < n; i++) {
            cin >> a >> b >> c;
            v[a].push_back({b, c});
            v[b].push_back({a, c});
        }

        dfs(0);
        visited.reset();
        exc(0);

        cout << ans << '\n';

        v.clear();
    }

    return 0;
}