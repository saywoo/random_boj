#include <bits/stdc++.h>
using namespace std;

int n, k, tmp, ans = 1e9;
vector<int> st, v;

int query(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 1e9;
    else if (s <= l && r <= e) return st[p];
    else return min(query(l, (l + r) / 2, s, e, p * 2), query((l + r) / 2 + 1, r, s, e, p * 2 + 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    for (tmp = 1; tmp < n; tmp *= 2) {}
    st.resize(tmp * 2, 1e9); v.resize(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++) st[tmp+i] = v[i+1] - v[i];
    for (int i = tmp - 1; i; i--) st[i] = min(st[i*2], st[i*2+1]);

    int rem = n - k;

    for (int i = 1; i + rem - 1 <= n; i++) {
        int M = v[i+rem-2] - v[i-1];
        int m = query(1, tmp, i, i + rem - 2, 1);

        ans = min(M + m, ans);
    }

    cout << ans << '\n';

    return 0;
}