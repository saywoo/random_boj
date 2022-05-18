#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m, a, b, c, s, e, ans = 0;
vector<vector<pr>> v;
vector<int> visited;
vector<pr> dist;

void dijkstra()
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    for (int i = 1; i <= n; i++) dist[i] = {1e9, 0};
    dist[s] = {0, 0}; pq.push({0, s});

    while (pq.size()) {
        pr t = pq.top();
        pq.pop();

        if (visited[t.B]) continue;
        visited[t.B] = true;

        for (auto i: v[t.B]) {
            if (dist[i.A].A - dist[i.A].B > dist[t.B].A + i.B - max(dist[t.B].B, i.B)) {
                dist[i.A].A = dist[t.B].A + i.B;
                dist[i.A].B = max(dist[t.B].B, i.B);
                pq.push({dist[i.A].A - dist[i.A].B, i.A});
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1); dist.resize(n + 1); visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c; ans += c;
        v[a].push_back({b, c}); v[b].push_back({a, c});
    }

    cin >> s >> e;

    dijkstra();
    cout << ans - dist[e].A + dist[e].B << '\n';

    return 0;
}