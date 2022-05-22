#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> str;

    bool ok = false;

    n--;
    if (str[n] == 'q'  || str[n] == 'r' || str[n] == 'w' || str[n] == 'e' || str[n] == 't' || str[n] == 'a' ||
    str[n] == 's' || str[n] == 'd' ||str[n] == 'f' || str[n] == 'g' || str[n] == 'z' || str[n] == 'x' || str[n] == 'c' || str[n] == 'v') ok = true;
    if (ok) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}