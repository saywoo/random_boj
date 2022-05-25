#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll d, n, m;
vector<ll> v, dist;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> d >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    v.push_back(0); v.push_back(d);

    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++) dist.push_back(v[i] - v[i-1]);

    ll low = 0; ll high = 1e12;

    vector<ll> bu = dist;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        dist = bu; int c = 0;
        
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] < mid) {
                c++;
                if (i != dist.size() - 1) dist[i+1] += dist[i];
            }
        }

        if (c <= m) low = mid;
        else high = mid;
    }

    cout << low << '\n';

    return 0;
}