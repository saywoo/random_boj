#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n + 1); b.resize(n + 1); c.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) c[i] = true;
    }

    for (int i = 1; i <= n; i++) cout << c[i] << " ";
    
    return 0;
}