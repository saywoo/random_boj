#include <bits/stdc++.h>
using namespace std;

int n, s = 0;
vector<int> v;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; v.resize(n); dp.resize(n + 1);
    for (int i = 0; i < n; i++) { 
        cin >> v[i]; s += v[i]; 
    }

    sort(v.begin(), v.end());

    for (int i = 0; i <= n; i++) dp[i].resize(n + 1);
    for (int i = 0; i < n; i++) {

        // dp
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < j; k++) {
                if (j - 1 == i) {

                }
                else {
                    
                }
            }
        }
    }
    
    return 0;
}