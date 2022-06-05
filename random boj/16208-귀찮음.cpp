#include <bits/stdc++.h>
using namespace std;

long long int n, s, ans;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; s += v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        s -= v[i];
        ans += s * v[i];
    }

    cout << ans << '\n';

    return 0;
}