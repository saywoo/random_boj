#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int low = 1; int high = 1e9;

    while (low + 1 < high) {
        int mid = (low + high) / 2;

        // cout << low << " " << mid << " " << high << '\n';

        int c = 1; int tmp = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] > mid) c = 1e9;
            if (tmp + v[i] > mid) {
                c++; tmp = v[i];
            }
            else tmp += v[i];
        }

        if (c <= m) high = mid;
        else low = mid;
    }

    cout << high << '\n';

    int tmp = 0; int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp + v[i] > high) {
            ans.push_back(cnt); tmp = v[i]; cnt = 1;
        }
        else { cnt++; tmp += v[i]; }
    }

    ans.push_back(cnt);

    int p = ans.size() - 1;

    while (ans.size() != m) {
        if (ans[p] == 1) p--;
        else {
            ans[p]--;
            ans.push_back(1);
        }
    }

    for (int i: ans) cout << i << " ";

    return 0;
}