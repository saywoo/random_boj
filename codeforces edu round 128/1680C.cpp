#include <bits/stdc++.h>
using namespace std;

int t; 
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; 

    while (t--) {
        cin >> str; int c = 0; int a = 0; int b = 0; int ans = 1e9;
        int n = str.length();

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '1') c++;
        }
        
        for (int i = 0; i < c; i++) {
            if (str[i] == '1') a++;
            else b++;
        }


        ans = min(ans, max(c - a, b)); 

        for (int i = c; i < n; i++) {
            if (str[i] == '1') a++;
            else b++;

            if (str[i-c] == '1') a--;
            else b--;

            ans = min(ans, max(c - a, b)); 
        }


        cout << ans << '\n';
    }

    return 0;
}