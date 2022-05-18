#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
set<int> col[100001];
vector<int> parent, v;

int Find(int x)
{
    if (x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x); y = Find(y);
    if (x != y) {
        if (col[y].size() > col[x].size()) {
            for (auto i: col[x]) col[y].insert(i);
            col[x].clear();
            parent[x] = y;
        }
        else {
            for (auto i: col[y]) col[x].insert(i);
            col[y].clear();
            parent[y] = x;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    parent.resize(n + 1); v.resize(n + 1);

    for (int i = 2; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> c; col[i].insert(c);
    }

    stack<pair<int, int> > stk;

    for (int i = 1; i <= m + n - 1; i++) {
        cin >> a >> b;
        stk.push({a, b});
    }

    stack<int> ans;

    while (stk.size()) {
        a = stk.top().first; b = stk.top().second;
        stk.pop();

        if (a == 1) {
            Union(b, v[b]);
        }
        else {
            b = Find(b);
            ans.push(col[parent[b]].size());
        }
    }

    while (ans.size()) {
        cout << ans.top() << '\n';
        ans.pop();
    }

    return 0;
}