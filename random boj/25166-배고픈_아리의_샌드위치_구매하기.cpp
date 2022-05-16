#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    if (n <= 1023) cout << "No thanks" << '\n';
    else {
        n -= 1023; int t = n & m;

        if (t == m && n <= m) cout << "Thanks" << '\n';
        else cout << "Impossible" << '\n';
    }

    return 0;
}