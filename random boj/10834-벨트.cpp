#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
long long int ans_1 = 1, ans_2 = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (c) ans_2 ^= 1;
        ans_1 = (ans_1 / a) * b;
    }

    cout << ans_2 << " " << ans_1 << '\n';

    return 0;
}   