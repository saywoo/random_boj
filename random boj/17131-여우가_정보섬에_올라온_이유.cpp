#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long int ll;
struct pos {
    int x, y;
    bool operator<(const pos &temp) {
        if (x == temp.x) return y > temp.y;
        else return x < temp.x;
    }
};
ll n, ans = 0, tmp = 1;
vector<pos> v;
vector<vector<int>> mst;

int query(int s, int e, int l, int r, int p, int num)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return (r - l + 1) - (upper_bound(mst[p].begin(), mst[p].end(), num) - mst[p].begin());
    else return query(s, e, l, (l + r) / 2, p * 2, num) + query(s, e, (l + r) / 2 + 1, r, p * 2 + 1, num);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (tmp = 1; tmp < n; tmp *= 2) {}
    v.resize(n); mst.resize(tmp * 2);
    for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end());

    for (int i = tmp; i < tmp + n; i++) mst[i].push_back(v[i-tmp].y);
    for (int i = tmp - 1; i; i--) {
        int a = 0; int b = 0;
        while (a != mst[i*2].size() || b != mst[i*2+1].size()) {
            if (a == mst[i*2].size()) { mst[i].push_back(mst[i*2+1][b]); b++; continue; }
            if (b == mst[i*2+1].size()) { mst[i].push_back(mst[i*2][a]); a++; continue; }
            if (mst[i*2][a] < mst[i*2+1][b]) { mst[i].push_back(mst[i*2][a]); a++; }
            else  { mst[i].push_back(mst[i*2+1][b]); b++; }
        }
    }

    int bf = 0;

    for (int i = 0; i < n; i++) {
        if (i) {
            ll temp = query(i + 2, n, 1, tmp, 1, v[i].y);
            if (v[i].x != v[i-1].x) bf = i;
            temp *= query(1, bf, 1, tmp, 1, v[i].y);
            temp %= MOD;

            ans = (ans + temp) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}