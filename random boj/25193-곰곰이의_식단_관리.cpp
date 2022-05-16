#include <bits/stdc++.h>
using namespace std;

int n, c = 0;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] != 'C') c++;
    }

    if (c) cout << n / (c + 1) << '\n';
    else cout << n << '\n';

    return 0;
}