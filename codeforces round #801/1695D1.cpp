#include <bits/stdc++.h>
using namespace std;

int t, n, a, b;
vector<int> ind;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; int mx = 0; ind.resize(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            ind[a]++; ind[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (ind[i] == 1) mx++;
        }

        if (mx == 0) cout << 0 << '\n';
        else cout << mx - 1 << '\n';
        ind.clear();
    }

    return 0;
}