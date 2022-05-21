#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    while (n--) {
        cin >> c;
        if (c * c > a * a + b * b) cout << "NE" << '\n';
        else cout << "DA" << '\n';
    }

    return 0;
}