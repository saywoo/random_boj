#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
set<pr> mem[101][101];
vector<vector<int>> visited;
vector<pr> p;
int n, m, k, a, b, c, d, ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int x, int y)
{
    queue<pr> q;
    q.push({x, y});

    while (q.size()) {
        pr t = q.front(); q.pop();

        if (visited[t.A][t.B]) continue;
        visited[t.A][t.B] = true;

        for (int i = 0; i < 4; i++) {
            int nx = t.A + dx[i]; int ny = t.B + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            if (!visited[nx][ny] && !mem[t.A][t.B].count({nx, ny})) q.push({nx, ny});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> m;
    visited.resize(n + 1); p.resize(k);

    for (int i = 1; i <= n; i++) visited[i].resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        mem[a][b].insert({c, d});
        mem[c][d].insert({a, b});
    }

    for (int i = 0; i < k; i++) cin >> p[i].A >> p[i].B;

    for (int i = 0; i < k; i++) {
        bfs(p[i].A, p[i].B);

        for (int j = i + 1; j < k; j++) {
            if (!visited[p[j].A][p[j].B]) ans++;
        }

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) visited[x][y] = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}