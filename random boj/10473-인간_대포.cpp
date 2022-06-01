#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<double, double> pr;
typedef pair<double, int> pp;
pr s, e;
int n;
double a, b;
vector<double> dist;
vector<pr> w;
vector<vector<pp>> v;
vector<bool> visited;

double f(pr x, pr y)
{
    return sqrt((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y));
}

void dijkstra()
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0.0, 0}); dist[0] = 0.0;

    while (pq.size()) {
        pp t = pq.top(); pq.pop();
        
        if (visited[t.Y]) continue;
        visited[t.Y] = true;

        for (auto i: v[t.Y]) {
            if (i.X + t.X < dist[i.Y]) {
                dist[i.Y] = i.X + t.X;
                pq.push({dist[i.Y], i.Y});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << fixed;
    cout.precision(6);

    cin >> s.X >> s.Y >> e.X >> e.Y;
    cin >> n;

    w.push_back(s); w.push_back(e);
    visited.resize(n + 2); dist.resize(n + 2, 1e9); v.resize(n + 2);

    for (int i = 2; i <= n + 1; i++) {
        cin >> a >> b;
        w.push_back({a, b});
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (i == j) continue;
            if (i == 0 || i == 1) v[i].push_back({f(w[i], w[j]) / 5.0, j});
            else {
                double tmp = f(w[i], w[j]); 
                if (tmp < 50.0) {
                    double temp = 50.0 - tmp;
                    v[i].push_back({min(temp + 10.0, tmp) / 5.0, j});
                }
                else {
                    double temp = tmp - 50.0;
                    v[i].push_back({min(temp + 10.0, tmp) / 5.0, j});
                }
            }
        }
    }

    dijkstra();

    cout << dist[1] << '\n';

    return 0;
}