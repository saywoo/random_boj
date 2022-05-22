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
        cin >> str; a = 0; 

        v.resize(n + 1);

        for (int i = 0; i < n; i++) a += str[i] - '0';

        if (a & 1) { NO continue; }
        YES

        b = a / 2 - 1;

        for (int i = 0; i < n; i++) {
            if (str[i] == '0') v[i+1] = 2;
            else if (b) v[i+1] = 3;
            else v[i+1] = 1;
        }

        int l = 2; int r = n;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < v[i]; j++) {
                if (j % 2) { cout << i << " " << r << '\n'; v[r]--; r--; }
                else { cout << i << " " << l << '\n'; v[l]--; l++; }
            }
            v[i] = 0;
        }

        v.clear();
    }
    return 0;
}