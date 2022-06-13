#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
#define MOD 1000000007
typedef pair<int, int> pr;
int n, k, tmp, ans = 0;
vector<int> v, st[12], pos;
vector<pr> zp;
vector<vector<int>> dp;

bool cmp(pr x, pr y) {
    if (x.A == y.A) return x.B > y.B;
    else return x.A < y.A;
}

void Update(int p, int x, int num)
{
    st[x][p] = (num + st[x][p]) % MOD;

    while (p != 1) {
        p /= 2;
        st[x][p] = (st[x][p*2] + st[x][p*2+1]) % MOD;
    }
}

int query(int l, int r, int s, int e, int p, int x)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return st[x][p];
    else return (query(l, (l + r) / 2, s, e, p * 2, x) + query((l + r) / 2 + 1, r, s, e, p * 2 + 1, x)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    k = 11;
    for (tmp = 1; tmp < n; tmp *= 2) {}
    for (int i = 0; i <= k; i++) st[i].resize(tmp * 2);

    v.resize(n); pos.resize(n); dp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        dp[i].resize(k + 1);
        zp.push_back({v[i], i});
    }

    sort(zp.begin(), zp.end(), cmp);

    for (int i = 0; i < n; i++) pos[zp[i].B] = i + 1;

    for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= k; j++) {
            if (i + 1 < j) continue;
            dp[i][j] = query(1, tmp, 1, pos[i] - 1, 1, j - 1);
            Update(pos[i] + tmp - 1, j, dp[i][j]);
        }
        Update(pos[i] + tmp - 1, 1, dp[i][1]);
    }

    for (int i = 0; i < n; i++) ans = (ans + dp[i][k]) % MOD; 

    cout << ans << '\n';

    return 0;
}