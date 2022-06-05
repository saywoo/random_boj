#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string str;
ll ans = 0, cnt = 0;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (i) {
            if (str[i] == '(' && str[i-1] == '(') cnt++;
            if (str[i] == ')' && str[i-1] == ')') ans += cnt;
        }
    }

    cout << ans << '\n';

    return 0;
}