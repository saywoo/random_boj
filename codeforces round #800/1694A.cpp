#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> a >> b;

        while (a && b) {
            cout << "01";
            a--; b--;
        }

        for (int i = 0; i < a; i++) cout << '0';
        for (int i = 0; i < b; i++) cout << '1';
        cout << '\n';
    }

    return 0;
}