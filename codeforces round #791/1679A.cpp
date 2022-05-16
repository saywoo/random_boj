#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; 

    while (t--) {
        cin >> n;

        if (n & 1 || n < 4) { cout << -1 << '\n'; continue; }
        else {
            if (n % 6 == 2) cout << n / 6 - 1 + 2 << " ";
            else if (n % 6 == 4) cout << n / 6 + 1 << " ";
            else cout << n / 6 << " ";

            if (n % 4 == 2) cout << n / 4 - 1 + 1 << '\n';
            else cout << n / 4 << '\n'; 
        }
    }

    return 0;
}