#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, ans = 0, m;
stack<pr> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m; ll tmp = 0;

        while (s.size()) {
            if (s.top().A < m) {
                ans += s.top().B; s.pop();
            }
            else break;
        }

        if (s.empty()) s.push({m, 1});
        else {
            if (s.top().A == m) {
                pr t = s.top(); s.pop();

                ans += t.B;
                if (s.size()) ans++;
                t.B++; s.push(t);
            }
            else {
                ans++;
                s.push({m, 1});
            }
        }
    }

    cout << ans << '\n';

    return 0;
}