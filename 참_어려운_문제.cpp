#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n, a, b, dfsn = 0;
vector<int> col, visited, finished, col_s, col_e;
vector<vector<int>> v;

void dfs(int p)
{
    visited[p] = ++dfsn;

    for (int i: v[p]) {
        if (!visited[i]) dfs(i);
    }

    finished[p] = dfsn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    col.resize(n + 1); v.resize(n + 1); visited.resize(n + 1); finished.resize(n + 1);
    col_s.resize(n + 1, 0); col_e.resize(n + 1, n);
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        col_s[col[i]] = min(visited[i] + 1, col_s[col[i]]);
        col_e[col[i]]
    }

    return 0;
}