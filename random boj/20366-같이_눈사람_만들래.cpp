#include <bits/stdc++.h>
using namespace std;

int n, ans = 2e9;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i + 2; j--) {
            int l = i + 1; int r = j - 1; int sa = v[i] + v[j];
            while (l < r) {
                int sb = v[l] + v[r];
                ans = min(ans, abs(sa - sb));
                if (sa < sb) r--;
                else l++; 
            }
        }
    }

    cout << ans << '\n';

    return 0;
}