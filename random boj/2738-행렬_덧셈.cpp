#include <bits/stdc++.h>
using namespace std;

int n, m, a[110][110], b[101][110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> b[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] + b[i][j] << " ";
        cout << '\n';
    }

    return 0;
}