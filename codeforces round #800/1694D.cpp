#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, t, p, ans;
vector<pr> v;
vector<ll> dp, ind, tree;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; ans = 0;
        tree.resize(n + 1); v.resize(n + 1); ind.resize(n + 1); dp.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> p;
            ind[p]++;
            tree[i] = p;
        }

        for (int i = 1; i <= n; i++) {
            cin >> v[i].A >> v[i].B;
            if (!ind[i]) q.push(i);
        }

        while (q.size()) {
            p = q.front(); q.pop();

            if (dp[p] < v[p].A) {
                ans++; dp[p] = v[p].B;
            }
            else dp[p] = min(dp[p], v[p].B);

            dp[tree[p]] += dp[p];
            ind[tree[p]]--;
            if (!ind[tree[p]]) q.push(tree[p]);
        }

        cout << ans << '\n';

        tree.clear(); v.clear(); ind.clear(); dp.clear();
    }

    return 0;
}