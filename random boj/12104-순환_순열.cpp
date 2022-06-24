#include <bits/stdc++.h>
using namespace std;

string a, b;
int n, ans = 0;
vector<int> fail;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    n = a.length();
    b = b + b; fail.resize(n + 1);

    for (int i = 1, j = 0; i < n; i++) {
        while (j && a[i] != a[j]) j = fail[j-1];
        if (a[i] == a[j]) fail[i] = ++j;
    }

    for (int i = 0, j = 0; i < n * 2 - 1; i++) {
        while (j && b[i] != a[j]) j = fail[j-1];
        if (b[i] == a[j]) {
            if (j == n - 1) {
                ans++;
                j = fail[j];
            }
            else j++;
        }
    }

    cout << ans << '\n';

    return 0;
}