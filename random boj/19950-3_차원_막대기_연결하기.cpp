#include <bits/stdc++.h>
using namespace std;

int s[3], e[3], n, k[101], a, b, c, sq_a, sq_b, sq_c, siz;
bool ok = true;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++) cin >> s[i];
    for (int i = 0; i < 3; i++) cin >> e[i];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k[i]; 
        siz += k[i];
        sq_a = max(sq_a, k[i]);
    }

    sq_b = siz - sq_a;
    b = (siz - sq_a) * (siz - sq_a);
    a = sq_a * sq_a;

    for (int i = 0; i < 3; i++) {
        c += (s[i] - e[i]) * (s[i] - e[i]);
    }

    sq_c = sqrt(c);

    if (a + b < c) ok = false;
    if (sq_b + sq_c < sq_a) ok = false;

    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}