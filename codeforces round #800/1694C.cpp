#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; v.resize(n); ll s = 0; bool ok = true; bool flag = true;
        for (int i = 0; i < n; i++) {
            cin >> v[i]; 
            if (!flag && v[i]) ok = false;
            s += v[i];
            if (s < 0) ok = false;
            else if (!s) flag = false;
        }

        if (s) {
            cout << "No" << '\n';
            v.clear(); continue;
        }

        if (ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}