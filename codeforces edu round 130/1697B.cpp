#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, x, y;
vector<ll> v, ps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    v.resize(n + 1); ps.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) ps[i] = v[i] + ps[i-1];
    
    for (int i = 0; i < q; i++) {
        cin >> x >> y;

        cout << ps[n-x+y] - ps[n-x] << '\n';
    }

    return 0;
}