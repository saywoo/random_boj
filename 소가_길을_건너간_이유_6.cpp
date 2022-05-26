#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<string, int> pr;
vector<vector<pr>> v;
int n, m, q, a, b, c, d, ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;

    v.resize(n + 1);

    for (int i = 1; i <= n; i++) v[i].resize(n + 1, {"0000", 0});

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;

        for (int j = 0; j < 4; j++) {
            int nx = a + dx[i]; int ny = b + dy[i];
            if (nx == c && ny == d) {v[i][j]}
        }
    }

    return 0;
}