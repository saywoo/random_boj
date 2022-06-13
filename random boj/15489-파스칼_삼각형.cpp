#include <bits/stdc++.h>
using namespace std;

long long int dp[101][101], r, c, w, ans = 0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    cin >> r >> c >> w;

    for (int i = r; i < r + w; i++) {
        int cnt = i - r;
        for (int j = c; j <= c + cnt; j++) ans += dp[i][j];
    }

    cout << ans << '\n';

    return 0;
}