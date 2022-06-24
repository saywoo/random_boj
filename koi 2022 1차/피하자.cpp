#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans = 1e18;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int p = 0; ll tmp = 0;

    for (int i = 0; i < n; i++) {
        if (!(v[i] & 1)) {
            tmp += i - p;
            p++;
        }
    }

    ans = min(ans, tmp);
    tmp = 0; p = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] & 1) {
            tmp += i - p;
            p++;
        }
    }

    ans = min(ans, tmp);

    cout << ans << '\n';

    return 0;
}
