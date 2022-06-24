#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int ll;
int N, M;
ll n, m;
vector<int> A, B;
vector<pair<int, int>> P;
vector<vector<int>> l, r;
set<pair<int, int>> s;
vector<vector<pair<int, int>>> vx, vy;

ll max_bananas(vector<int> a, vector<int> b, vector<pair<int, int>> p)
{
    n = a.size();
    m = p.size();
    ll ans = 0;

    vx.resize(n + 1); vy.resize(n + 1);
    l.resize(n + 1); r.resize(n + 1);

    for (int i = 0; i < m; i++) {
        s.insert({p[i].x, p[i].y});
        l[p[i].x].push_back(p[i].y);
        r[p[i].y].push_back(p[i].x);
    }

    for (int i = 1; i <= n; i++) {
        sort(l[i].begin(), l[i].end());
        sort(r[i].begin(), r[i].end());

        for (int j = 1; j < l[i].size(); j++) {
            vx[l[i][j-1]].push_back()
        }

        for (int j = 1; j < r[i].size(); j++) {

        }
    }


    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> p[i].x >> p[i].y;

    cout << max_bananas(a, b, p) << '\n';

    return 0;
}