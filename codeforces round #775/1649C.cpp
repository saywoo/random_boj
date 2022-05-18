#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, m, ans = 0;
vector<vector<ll>> v;
vector<pr> w;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1); w.resize(100001);

    for (int i = 1; i <= n; i++) {
        v[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            int p = v[i][j];
            ans += i * w[p].B - w[p].A;
            w[p].A += i; w[p].B++; 
        }
    }

    for (int i = 1; i <= 100000; i++) w[i] = {0, 0};

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int p = v[i][j];
            ans += j * w[p].B - w[p].A;
            w[p].A += j; w[p].B++; 
        }
    }

    cout << ans << '\n';

    return 0;
}