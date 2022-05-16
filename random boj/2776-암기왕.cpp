#include <bits/stdc++.h>
using namespace std;

int t, n, m, q;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        
        cin >> m;
        while (m--) {
            cin >> q;

            cout << binary_search(v.begin(), v.end(), q) << '\n';
        }

        v.clear();
    }

    return 0;
}