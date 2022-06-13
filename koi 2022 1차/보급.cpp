#include <bits/stdc++.h>
using namespace std;

struct query {
    int x, y, s, e, p, l, r;
    bool operator<(const query &a) const {
        if (a.x == x) return y < a.y;
        else return x < a.x;
    }
};

struct tri {
    int x, y, p;
    bool operator<(const tri &a) const {
        if (a.y == y) return x > a.x;
        else return y > a.y;
    }
};

bool cmp(query a, query b)
{
    if (a.s == b.s) return a.e > b.e;
    else return a.s < b.s;
}

bool ok = true;
int n, tmp;
vector<query> v;
vector<int> st, ans;

int Max(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return st[p];
    else return max(Max(l, (l + r) / 2, s, e, p * 2), Max((l + r) / 2 + 1, r, s, e, p * 2 + 1));
}

int Min(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 1e9;
    else if (s <= l && r <= e) return st[p];
    else return min(Min(l, (l + r) / 2, s, e, p * 2), Min((l + r) / 2 + 1, r, s, e, p * 2 + 1));
}

void Update_mx(int p, int val)
{
    st[p] = val;

    while (p != 1) {
        p /= 2;
        st[p] = max(st[p*2], st[p*2+1]);
    }
}

void Update_mn(int p, int val)
{
    st[p] = val;

    while (p != 1) {
        p /= 2;
        st[p] = min(st[p*2], st[p*2+1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (tmp = 1; tmp < n; tmp *= 2) {}
    ans.resize(n); v.resize(n); st.resize(tmp * 2, 1e9);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].s >> v[i].e;
        v[i].p = i; v[i].l = 0; v[i].r = 0;
    }

    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--) {
        v[i].r = Min(1, tmp, v[i].y, tmp, 1) - 1;
        Update_mn(v[i].y + tmp - 1, v[i].e);
    }

    for (int i = 0; i < st.size(); i++) st[i] = 0;

    for (int i = 0; i < n; i++) {
        v[i].l = Max(1, tmp, 1, v[i].y, 1) + 1;
        Update_mx(v[i].y + tmp - 1, v[i].s);
        v[i].s = max(v[i].s, v[i].l);
        v[i].e = min(v[i].e, v[i].r);
        if (v[i].s > v[i].e) ok = false;
    }

    sort(v.begin(), v.end(), cmp);

    priority_queue<tri> pq;

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        while (cnt < n && v[cnt].s <= i) pq.push({v[cnt].s, v[cnt].e, v[cnt++].p});
        if (!pq.size()) {
            ok = false; break;
        }

        ans[pq.top().p] = i;
        pq.pop();
    }

    if (ok) {
        cout << "YES" << '\n';
        for (int i: ans) cout << i << " ";
    }
    else cout << "NO" << '\n';

    return 0;
}
