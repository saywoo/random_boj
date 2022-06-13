#include <bits/stdc++.h>
using namespace std;

int r, c, v[3][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) cin >> v[i][j];
    }

    cout << v[r][c] << '\n';


    return 0;
}