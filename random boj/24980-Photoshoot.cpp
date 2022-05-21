#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> str;

    for (int i = n - 1; i >= 1; i -= 2) {
        if (str[i] == str[i-1]) continue;
        if (str[i] == 'G' && ans % 2) ans++;
        if (str[i] == 'H' && ans % 2 == 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}