#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a <= b) ans = min(ans, b);
    }
    
    if (ans != 1e9) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}
