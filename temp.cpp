#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
vector<int> x(26), y(26), c, d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> a >> b;

    bool ok = true;

    if (a[0] != b[0] || a[n-1] != b[n-1]) ok = false;

    for (int i = 1; i < n - 1; i++) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
            x[a[i]-'a']++;
        }
        else c.push_back(a[i]);

        if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') {
            y[b[i]-'a']++;
        }
        else d.push_back(b[i]);
    }

    if (c.size() != d.size()) ok = false;
    else {
        for (int i = 0; i < c.size(); i++) {
            if (c[i] != d[i]) ok = false;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (x[i] != y[i]) ok = false;
    }

    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}