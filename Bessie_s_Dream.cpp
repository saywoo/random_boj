#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v, visited[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(m);
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }

    return 0;
}