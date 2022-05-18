#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> d;
        bool ok = false;
        for (int i = 1; i <= 50; i++) {
            if (a <= i && i <= b && c <= i && i <= d) { cout << i << '\n'; ok = true; break; }
        }

        if (!ok) cout << a + c << '\n';
    }

    return 0;
}