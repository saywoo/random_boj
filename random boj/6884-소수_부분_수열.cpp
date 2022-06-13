#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> v, pn;
bitset<100000001> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i <= 10000; i++) {
        if (a[i]) continue;
        for (int j = i * 2; j <= 100000000; j += i) a[j] = true;
    }

    cin >> t;

    while (t--) {
        cin >> n; v.resize(n); bool ok = false;
        for (int i = 0; i < n; i++) cin >> v[i];
        
        for (int i = 2; i <= n; i++) {
            int ps = 0;
            for (int j = 0; j < i; j++) ps += v[j];

            if (!a[ps]) {
                cout << "Shortest primed subsequence is length " << i << ": ";
                for (int j = 0; j < i; j++) cout << v[j] << " ";
                cout << '\n';

                ok = true;
                break;
            }

            for (int j = i; j < n; j++) {
                ps = ps + v[j] - v[j-i];
                if (!a[ps]) {
                    cout << "Shortest primed subsequence is length " << i << ": ";
                    for (int k = j - i + 1; k <= j; k++) cout << v[k] << " ";
                    cout << '\n';

                    ok = true;
                    break;
                }
            }

            if (ok) break;
        }

        if (!ok) cout << "This sequence is anti-primed." << '\n';

        v.clear();
    }

    return 0;
}