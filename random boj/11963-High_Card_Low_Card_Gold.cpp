#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, ck[100100];
vector<int> v, w, tmp;

bool cmp(int x, int y)
{
    return v[x] > v[y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i]; ck[v[i]] = true;
    }

    for (int i = 1; i <= n * 2; i++) {
        if (!ck[i]) w.push_back(i);
    }

    for (int i = 0; i < n / 2; i++) tmp.push_back(i);

    sort(tmp.begin(), tmp.end(), cmp);

    for (int i = 0; i < n / 2; i++) {
        if (v[tmp[i]] > w.back()) continue;
        else {
            w.pop_back(); ans++;
        }
    }

    tmp.clear();

    for (int i = n / 2; i < n; i++) tmp.push_back(i);

    sort(tmp.begin(), tmp.end(), cmp);

    reverse(w.begin(), w.end());
    reverse(tmp.begin(), tmp.end());

    for (int i = 0; i < n / 2; i++) {
        if (v[tmp[i]] < w.back()) continue;
        else {
            w.pop_back(); ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}