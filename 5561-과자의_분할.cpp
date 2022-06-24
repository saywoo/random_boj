#include <bits/stdc++.h>
using namespace std;

int n, dp[2][10001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 1; i < n; i++) {
        cin >> v[i];
        for (int j = i; j > 1; j--) dp[1][j] = min(dp[0][j-1], dp[0][i-j+1] + v[i]);
        dp[1][1] = v[i];
        for (int j = 0; j <= i; j++) dp[0][j] = dp[1][j];
    }

    cout << dp[0][n/2] << '\n';

    return 0;
}