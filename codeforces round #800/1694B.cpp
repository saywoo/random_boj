#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> str;

        ll ans = n;

        for (int i = 1; i < n; i++) {
            if (str[i] == '1' && str[i-1] == '0') ans += i;
            if (str[i] == '0' && str[i-1] == '1') ans += i;
        }

        cout << ans << '\n';
    }

    return 0;
}