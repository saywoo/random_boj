#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m, k, a, b, c;
vector<vector<pr>> v;

void dijkstra(int s)
{
    priority_queue<
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b, c}); v[b].push_back({a, c});
    }

    dijkstra(1);

    return 0;
}