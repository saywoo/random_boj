#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> str;

        int m = 100;

        if (str.length() == 2) { cout << str[1] << '\n'; continue; }

        for (int i = 0; i < str.length(); i++) {
            m = min(m, (int)str[i]);
        }

        cout << m - '0' << '\n';
    }

    return 0;
}