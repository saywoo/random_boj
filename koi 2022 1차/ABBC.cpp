#include <bits/stdc++.h>
using namespace std;

string s;
int sn, c = 0, ans = 0;
queue<int> q, del;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    sn = s.length();
    for (int i = 0; i < sn; i++) {
        if (s[i] == 'B') q.push(i);
    }
    for (int i = 0; i < sn; i++) {
        if (s[i] == 'C' && q.size()) {
            if (q.front() < i) {
                s[q.front()] = '0';
                s[i] = '0';
                q.pop();
                ans++;
            }
        }
    }

    for (int i = 0; i < sn; i++) {
        if (s[i] == 'A') c++;
        if (s[i] == 'B' && c) { c--; ans++; }
    }

    cout << ans << '\n';

    return 0;
}
