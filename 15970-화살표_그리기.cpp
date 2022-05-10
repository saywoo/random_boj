#include <bits/stdc++.h>
using namespace std;

#define A second
#define B first
typedef long long int ll;
typedef pair<int, int> pr;
ll n, ans = 0;
vector<pr> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n); 
    for (int i = 0; i < n; i++) cin >> v[i].A >> v[i].B;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (!i) ans += v[i+1].A - v[i].A;
        else if (i == n - 1) ans += v[i].A - v[i-1].A;
        else {
            if (v[i+1].B != v[i].B) ans += v[i].A - v[i-1].A;
            else if (v[i].B != v[i-1].B) ans += v[i+1].A - v[i].A;
            else ans += min(v[i+1].A - v[i].A, v[i].A - v[i-1].A);
        }
    }

    cout << ans << '\n';

    return 0;
}