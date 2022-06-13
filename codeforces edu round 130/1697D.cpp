#include <bits/stdc++.h>
using namespace std;

int n, m;
char c;
string ans;
vector<int> pos;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) ans = ans + ' ';

    int bf = 0;

    for (int i = n - 1; i >= 0; i--) {
        int s = i + 1; int e = n;
        cout << "? 2 " << s << " " << e << '\n' << flush;
        cin >> m;

        if (m != bf) {
            cout << "? 1 " << s << '\n' << flush;
            cin >> c;
            ans[i] = c;
            bf = m;
            pos.push_back(s);
        }
        else {
            int siz = pos.size();
            int l = -1; int r = siz;

            while (l + 1 < r) {
                int mid = (l + r) / 2;
                cout << "? 2 " << s << " " << pos[mid] << '\n' << flush;
                cin >> m;

                if (m <= siz - mid) l = mid;
                else r = mid;
            }

            ans[i] = ans[pos[l]-1];
            pos[l] = s;
        }

        sort(pos.begin(), pos.end());
        reverse(pos.begin(), pos.end());
    }

    cout << "! " << ans << '\n' << flush;

    return 0;
}