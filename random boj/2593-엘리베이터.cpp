#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m, s, e;
vector<pr> v;
vector<vector<int>> g;
vector<int> visited, dist;
queue<int> q;

void bfs()
{
    while (q.size()) {
        int p = q.front(); q.pop();

        for (int i = 0;; i++) {
            int h = v[p].A + v[p].B * i;
            if (h > n) break;

            if (dist[h] == 1e9) dist[h] = p;

            for (int j: g[h]) {
                if (visited[j] != -1) continue;
                visited[j] = p;
                q.push(j);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(m); visited.resize(m, -1); dist.resize(n + 1, 1e9); g.resize(n + 1);
    for (int i = 0; i < m; i++) cin >> v[i].A >> v[i].B;

    cin >> s >> e;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < v[j].A) continue;
            else if ((i - v[j].A) % v[j].B == 0) g[i].push_back(j);
        }
    }

    for (int i = 0; i < m; i++) {
        if (s < v[i].A) continue;
        else if ((s - v[i].A) % v[i].B == 0) {
            q.push(i); visited[i] = 1e9;
        }
    }

    bfs();

    if (dist[e] == 1e9) cout << -1 << '\n';
    else {
        vector<int> ans;
        int p = dist[e];
        while (1) {
            if (p == 1e9) break;
            ans.push_back(p + 1);
            p = visited[p];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i: ans) cout << i << '\n';
    }

    return 0;
}