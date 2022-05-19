#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> a >> b >> c;

        ll x = 0; ll y = 0; ll z = 0;

        if (b >= a && b >= c) {
            y = b;
            x = y * 2 + a;
            z = x + c;
        }
        else if (a >= b && a >= c) {
            x = a;
            z = x * 2 + c;
            y = z + b;
        }
        else {
            z = c;
            y = z * 2 + b;
            x = y + a;
        }

        cout << x << " " << y << " " << z << '\n';
    }

    return 0;
}