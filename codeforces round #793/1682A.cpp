#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pr;
typedef pair<pair<ll, ll>, pair<ll, ll>> qud;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';
#define X first
#define Y second
#define A first.first
#define B first.second
#define C second.first
#define D second.second

ll t, n, m, a, b, c, d, cnt, ans;
vector<ll> v, w;
vector<vector<ll>> vv;
string str, sa, sb;
bool ok, flag;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> t;

    while (t--) {
        cin >> n; 
        cin >> str; ans = -1;

        if (n % 2) a = n / 2;
        else a = n / 2 - 1;

        for (int i = a; i >= 0; i--) {
            if (str[a] == str[i]) ans++;
            else break;
        }

        for (int i = a; i < n; i++) {
            if (str[a] == str[i]) ans++;
            else break;
        }

        cout << ans << '\n';
    }
    return 0;
}