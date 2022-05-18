#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; int a = 9999; int b = 0;
        v.resize(n + 1);
        for (int i = 0; i < n; i++) cin >> v[i];

        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                a = min(a, i);
                b = max(b, i);
            }
        }

        if (a == 9999) cout << 0 << '\n';
        else {
            cout << b - a + 2 << '\n';
        }
    }
    return 0;
}