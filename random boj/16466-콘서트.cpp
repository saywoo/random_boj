#include <bits/stdc++.h>
using namespace std;

int n, flag = false;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    if (v[0] > 1) { cout << 1 << '\n'; return 0; }

    for (int i = 0; i < n - 1; i++) {
        if (v[i+1] - v[i] != 1) {
            cout << v[i] + 1 << '\n';
            flag = true;
            break;
        }
    }

    if (!flag) cout << v[n-1] + 1 << '\n';

    return 0;
}