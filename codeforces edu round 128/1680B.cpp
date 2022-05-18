#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m, t;
vector<string> str;
vector<pr> query;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> m; int x = n; int y = m;
        bool ok = false;
        str.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            for (int j = 0; j < m; j++) {
                if (str[i][j] == 'R') {
                    query.push_back({i, j}); x = min(x, i); y = min(y, j);
                }
            }
        }


        for (int i = 0; i < query.size(); i++) {
            if (x == query[i].A && y == query[i].B) ok = true;
        }

        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        str.clear(); query.clear();
    }

    return 0;
}