#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; long long int ans = 0;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) {
            if (m >= v[i]) m -= v[i];
            else {
                ans += v[i] - m;
                m = 0;
            }
        }

        cout << ans << '\n';
        v.clear();
    }

    return 0;
}