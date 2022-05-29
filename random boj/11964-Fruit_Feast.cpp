#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, a, b, ans = 0;
bool dp[5000100][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    queue<pr> q;
    q.push({0, 1}); int mx = 0;

    while (q.size()) {
        pr t = q.front(); q.pop();

        if (t.A + a <= n) {
            if (!dp[t.A+a][t.B]) {
                dp[t.A+a][t.B] = true;
                q.push({t.A + a, t.B});
            }
        }

        if (t.A + b <= n) {
            if (!dp[t.A+b][t.B]) {
                dp[t.A+b][t.B] = true;
                q.push({t.A + b, t.B});
            }
        }

        if (t.B) {
            if (!dp[t.A/2][0]) {
                dp[t.A/2][0] = true;
                q.push({t.A / 2, 0});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i][0] || dp[i][1]) ans = i;
    }

    cout << ans << '\n';

    return 0;
}