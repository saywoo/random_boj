#include <bits/stdc++.h>
using namespace std;

#define a second
#define b first
typedef long long int ll;
typedef pair<ll, ll> pr;
ll n, k, m, ans = 0;
vector<pr> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b;

    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0; i < n; i++) {
        if (k) {
            if (v[i].b <= m) {
                m -= v[i].b;
                pq.push(v[i].a - v[i].b);
                ans++;
                k--;
            }
            else break;
        }
        else {
            if (pq.empty()) {
                if (v[i].a <= m) {
                    m -= v[i].a;
                    ans++;
                }
                else break;
            }

            if (pq.top() < v[i].a - v[i].b) {
                if (pq.top() + v[i].b <= m) {
                    m -= pq.top() + v[i].b;
                    ans++;
                    pq.pop();
                    pq.push(v[i].a - v[i].b);
                }
            }
            else {
                if (v[i].a <= m) {
                    m -= v[i].a;
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}