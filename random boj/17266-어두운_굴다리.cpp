#include <bits/stdc++.h>
using namespace std;

int n, m, a, bf = 0, ans = 0;
vector<int> dist;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        dist.push_back(a - bf);
        bf = a;
    }

    dist.push_back(n - bf);

    int siz = dist.size();

    for (int i = 0; i < siz; i++) {
        if (!i || i == siz - 1) ans = max(ans, dist[i]);
        else ans = max(ans, (dist[i] + 1) / 2);
    }

    cout << ans << '\n';

    return 0;
}