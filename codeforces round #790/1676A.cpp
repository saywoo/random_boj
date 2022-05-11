#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        int a = 0; int b = 0;

        for (int i = 0; i < 3; i++, n /= 10) a += n % 10;
        for (int i = 0; i < 3; i++, n /= 10) b += n % 10;

        if (a == b) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}