#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string str, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> str; bool f = false; ans = "";

        if (str[0] == '9') f = true;

        if (f) {
            int c = 0;
            for (int i = n - 1; i >= 0; i--) {
                if ('1' - str[i] - c < 0) {
                    str[i] = ('1' + 10 - str[i] - c) + 48;
                    c = 1;
                }
                else {
                    str[i] = ('1' - str[i] - c) + 48;
                    c = 0;
                }
            }

            cout << str << '\n';
        }
        else {
            for (int i = 0; i < n; i++) cout << '9' - str[i];
            cout << '\n';
        }
    }

    return 0;
}