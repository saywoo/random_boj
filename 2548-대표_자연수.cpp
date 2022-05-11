#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int ans = v[(n-1)/2];

    cout << ans << '\n';

    return 0;
}