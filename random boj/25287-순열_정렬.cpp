#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        v.resize(n); bool ok = true;
        for (int i = 0; i < n; i++) cin >> v[i];
        
        v[0] = min(v[0], n - v[0] + 1);
        for (int i = 1; i < n; i++) {
            int a = max(v[i], n - v[i] + 1);
            int b = min(v[i], n - v[i] + 1);

            if (v[i-1] > a) { ok = false; break; }
            else if (v[i-1] > b) v[i] = a;
            else v[i] = b;
        }

        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}