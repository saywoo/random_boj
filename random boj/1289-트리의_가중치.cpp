#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define MOD 1000000007
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, a, b, c;
vector<vector<pr>> v;
vector<ll> bf, dp;
bitset<100001> visited;

void dfs(int p) 
{
    visited[p] = true;

    ll tmp = 0;

    for (pr i: v[p]) {
        if (visited[i.A]) continue;
        dfs(i.A);
        bf[p] = (bf[p] + dp[i.A] + bf[i.A])  % MOD;
        bf[p] = (bf[p] + (tmp * (dp[i.A] + 1) % MOD) * i.B) % MOD;
        tmp = (tmp + (dp[i.A] + 1) * i.B) % MOD;
        dp[p] = (dp[p] + i.B * (dp[i.A] + 1)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1); dp.resize(n + 1, 0); bf.resize(n + 1, 0);
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1);

    cout << (dp[1] + bf[1]) % MOD << '\n';

    return 0;
}