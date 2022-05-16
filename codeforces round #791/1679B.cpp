#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a, b, c, f, s = 0, num;
vector<ll> v, ck;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    v.resize(n + 1); ck.resize(n + 1); f = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s += v[i];
    }
    
    for (int i = 1; i <= q; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;

            if (f != ck[b]) { v[b] = num; ck[b] = f; }
            s += c - v[b];

            v[b] = c;

            cout << s << '\n';
        }
        else {
            cin >> b;
            s = b * n;

            cout << s << '\n';
            f = i; num = b;
        }
    }

    return 0;
}