#include <bits/stdc++.h>
using namespace std;

int t;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; getline(cin, str);

    while (t--) {
        getline(cin, str); int s = 0;

        for (char i: str) {
            if (i == ' ') continue;
            s += i - 'A' + 1;
        }

        if (s == 100) cout << "PERFECT LIFE" << '\n';
        else cout << s << '\n';
    }

    return 0;
}