#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long int ll;
ll a = 0; 
int cnt[2000001], n, m;
ll ans[2000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m; int sm = sqrt(m);

        for (register int j = 1; j <= sm; j++) {
            if (m % j == 0) {
                ans[j] += j; cnt[j]++;
                if (j != m / j) { ans[m/j] += m / j; cnt[m/j]++; }
            }
        }
    }

    for (int i = 1; i <= 2000000; i++) {
        if (cnt[i] >= 2) a = max(a, ans[i]);
    } 
    cout << a << '\n';

    return 0;
}