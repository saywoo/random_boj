#include <bits/stdc++.h>
using namespace std;

#define V second
#define C first
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, m, k, s = 0;
vector<pr> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(k);
    for (int i = 0; i < k; i++) cin >> v[i].V >> v[i].C;

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        if (pq.size() < n) {
            s += v[i].V;
            pq.push(v[i].V);
        }
        else {
            if (pq.top() < v[i].V) {
                s = s - pq.top() + v[i].V;
                pq.pop();
                pq.push(v[i].V);
            }
        }

        if (s >= m && pq.size() == n) {
            cout << v[i].C << '\n';
            break;
        }
    }

    if (s < m) cout << -1 << '\n';
    return 0;
}