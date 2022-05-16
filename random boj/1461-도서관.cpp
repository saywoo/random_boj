#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
int n, m, a, ans = 0;
vector<int> l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < 0) l.push_back(a * -1);
        else r.push_back(a);
    }

    sort(all(l), greater<>()); sort(all(r), greater<>());

    if (!l.size()) ans = -1 * r[0];
    else if (!r.size()) ans = -1 * l[0];
    else ans = -1 * max(l[0], r[0]);

    for (int i = 0; i < l.size(); i += m) ans += l[i] * 2;
    for (int i = 0; i < r.size(); i += m) ans += r[i] * 2;
    cout << ans << '\n';

    return 0;
}