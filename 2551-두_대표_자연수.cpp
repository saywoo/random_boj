#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s;
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

    int ans_1 = v[(n-1)/2];
    ll ans_2 = s / n;
    if (s % n > n / 2) ans_2++;
    cout << ans_1 << " " << ans_2 << '\n';

    return 0;
}