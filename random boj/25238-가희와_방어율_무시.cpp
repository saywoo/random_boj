#include <bits/stdc++.h>
using namespace std;

double n, a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a;

    double m = n * (100.0 - a) / 100.0;

    if (m >= 100.0) cout << 0 << '\n';
    else cout << 1 << '\n';

    return 0;
}