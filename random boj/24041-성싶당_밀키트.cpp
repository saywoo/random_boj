#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
struct tri {
    ll s, l, o;
};
ll n, g, k;
vector<tri> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> g >> k;
    v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i].s >> v[i].l >> v[i].o;

    ll low = 0; ll high = 1e10;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;
        
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        __int128_t Sum = 0;

        for (int i = 0; i < n; i++) {
            ll tmp = v[i].s * max((ll)1, mid - v[i].l);
            Sum += tmp;
            
            if (v[i].o && k) {
                if (pq.size() < k) pq.push(tmp);
                else {
                    if (pq.top() < tmp) {
                        pq.pop(); pq.push(tmp);
                    }
                }
            }
        }

        while (pq.size()) {
            Sum -= pq.top(); pq.pop();
        }

        if (Sum <= g) low = mid;
        else high = mid;
    }

    cout << low << '\n';
    return 0;
}