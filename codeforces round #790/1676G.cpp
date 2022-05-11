#include <bits/stdc++.h>
using namespace std;

int t, n, cnt = 0, tmp, m;
vector<vector<int>> v;
vector<int> b_st, w_st, a, b;
string str;

int b_query(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return b_st[p];
    else return b_query(l, (l + r) / 2, s, e, p * 2) + b_query((l + r) / 2 + 1, r, s, e, p * 2 + 1);
}

int w_query(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return w_st[p];
    else return w_query(l, (l + r) / 2, s, e, p * 2) + w_query((l + r) / 2 + 1, r, s, e, p * 2 + 1);
}

void dfs(int p)
{
    a[p] = ++cnt;
    for (int i: v[p]) dfs(i);
    b[p] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n; cnt = 0;
        for (tmp = 1; tmp < n; tmp *= 2) {}
        b_st.resize(tmp * 2); w_st.resize(tmp * 2); v.resize(n + 1); a.resize(n + 1); b.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> m;
            v[m].push_back(i);
        }

        cin >> str;
        
        dfs(1);

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == 'B') b_st[tmp+a[i+1]-1] = 1;
            else w_st[tmp+a[i+1]-1] = 1;
        }

        for (int i = tmp - 1; i; i--) {
            b_st[i] = b_st[i*2] + b_st[i*2+1];
            w_st[i] = w_st[i*2] + w_st[i*2+1];
        }


        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = b_query(1, tmp, a[i], b[i], 1);
            int y = w_query(1, tmp, a[i], b[i], 1);

            if (x == y) ans++;
        }

        cout << ans << '\n';

        b_st.clear(); w_st.clear(); v.clear(); a.clear(); b.clear();
    }

    return 0;
}