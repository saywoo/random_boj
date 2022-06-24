#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; ll a = 1000000007, b = 1000000007, ap, bp;

        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if (n & 1) {
            cout << "Mike" << '\n';
            v.clear(); continue;
        }

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (b > v[i]) {
                    b = v[i]; bp = i;
                }
            }
            else {
                if (a > v[i]) {
                    a = v[i]; ap = i;
                }
            }
        }

        if (a < b) cout << "Joe" << '\n';
        else if (a == b && ap < bp) cout << "Joe" << '\n';
        else cout << "Mike" << '\n';

        v.clear();
    }

    return 0;
}