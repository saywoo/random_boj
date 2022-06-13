#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string a, b;
priority_queue<int, vector<int>, greater<int>> pos[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> a >> b;
        
        for (int i = 0; i < 3; i++) pos[i].push(1e9);

        for (int i = 0; i < n; i++) pos[a[i]-'a'].push(i);

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (b[i] == 'a') break;
                else if (b[i] == 'b') {
                    if (pos[1].top() < pos[2].top()) {
                        a[pos[0].top()] = 'b';
                        a[pos[1].top()] = 'a';
                        pos[0].push(pos[1].top());
                        pos[0].pop(); pos[1].pop();
                    }
                    else break;
                }
                else {
                    if (pos[2].top() < pos[0].top()) {
                        a[pos[1].top()] = 'c';
                        a[pos[2].top()] = 'b';
                        pos[1].push(pos[2].top());
                        pos[1].pop(); pos[2].pop();
                    }
                    else break;
                }
            }
            else {
                if (pos[0].top() == i) pos[0].pop();
                else if (pos[1].top() == i) pos[1].pop();
                else pos[2].pop();
            }
        }

        for (int i = 0; i < 3; i++) {
            while (pos[i].size()) pos[i].pop();
        }

        if (a == b) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}