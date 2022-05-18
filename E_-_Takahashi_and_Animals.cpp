#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct q {
    ll x, a, b;
};
bool cmp(q A, q B) { return A.x < B.x; }
ll n, ans = 0, m;
vector<q> v;
vector<int> ck;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ck.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m;
        if (i == n) v.push_back({m, i, 1});
        else v.push_back({m, i, i + 1});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i: v) {
        if (ck[i.a] && ck[i.b]) continue;
        else {
            ck[i.a] = 1; ck[i.b] = 1;
            ans += i.x;
        }
    }

    cout << ans << '\n';

    return 0;
}