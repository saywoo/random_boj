#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<string> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; 

    while (t--) {
        cin >> n >> m; v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int ans = 1e9;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = 0;
                for (int k = 0; k < m; k++) {
                    if (v[i][k] < v[j][k]) tmp += v[j][k] - v[i][k];
                    else tmp += v[i][k] - v[j][k];
                }

                ans = min(ans, tmp);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}