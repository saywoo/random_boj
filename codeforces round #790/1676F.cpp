#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
ll t, n, m;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; ll l = 1; ll r = 0;
        v.resize(n); map<int, int> ma;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            ma[v[i]]++;
        }

        ll a = -1; ll b = -1;

        for (auto i: ma) {
            if (a == -1) {
                if (i.B >= m) {
                    a = i.A; b = i.A;
                    if (b - a > r - l) { l = a; r = b; }
                }
            }
            else {
                if (i.B >= m && b + 1 == i.A) {
                    b++;
                    if (b - a > r - l) { l = a; r = b; }
                }
                else { 
                    a = -1; b = -1; 
                    if (i.B >= m) { a = i.A; b = i.A; }
                }
            }
        }

        if (l > r) cout << -1 << '\n';
        else cout << l << " " << r << '\n';

        v.clear(); 
    }

    return 0;
}