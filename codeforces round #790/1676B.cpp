#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; v.resize(n); int s = 0;

        for (int i = 0; i < n; i++) {
            cin >> v[i]; s += v[i];
        }

        cout << s - v[(min_element(v.begin(), v.end()) - v.begin())] * n << '\n';
        v.clear();
    }

    return 0;
}