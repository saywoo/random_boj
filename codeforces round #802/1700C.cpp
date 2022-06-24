#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, ans = 0, mn;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; v.resize(n); ans = 0; mn = 1e9 + 1;
        for (int i = 0; i < n; i++) cin >> v[i];

        if (v[0] < v[n - 1]) {
            ll c = 0;
            for (int i = 0; i < n - 1; i++) {
                if (v[i] > v[i+1]) {
                    c += v[i] - v[i+1];
                }
            }

            ll a = v[0] - c;
            cout << c + abs(a) + abs(v[n-1] - a) << '\n';
        }
        else {
            ll c = 0;
            for (int i = n - 1; i; i--) {
                if (v[i] > v[i-1]) {
                    c += v[i] - v[i-1];
                }
            }

            ll a = v[n-1] - c;
            cout << c + abs(a) + abs(v[0] - a) << '\n';
        }

        v.clear();
    }

    return 0;
}