#include <bits/stdc++.h>
using namespace std;

string str;
int n;
vector<vector<int>> fail;
vector<int> p, dp;
vector<string> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str >> n;
    int sn = str.length();
    dp.resize(sn + 1); fail.resize(n); p.resize(n, 0); s.resize(n);

    for (int l = 0; l < n; l++) {
        cin >> s[l];
        fail[l].resize(s[l].length() + 1);

        for (int i = 1, j = 0; i < s[l].length(); i++) {
            while (j && s[l][i] != s[l][j]) j = fail[l][j-1];
            if (s[l][i] == s[l][j]) fail[l][i] = ++j;
        }
    }

    for (int i = 0; i < sn; i++) {
        dp[i+1] = dp[i];
        for (int k = 0; k < n; k++) {
            while (p[k] && str[i] != s[k][p[k]]) p[k] = fail[k][p[k]-1];
            if (str[i] == s[k][p[k]]) {
                if (p[k] == s[k].length() - 1) {
                    dp[i+1] = max(dp[i+1], dp[i+1-(int)s[k].length()] + (int)s[k].length());
                    p[k] = fail[k][p[k]];
                }
                else p[k]++;
            }
        }
    }

    if (dp[sn] == sn) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}