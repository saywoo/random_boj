#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string str;
bitset<26> v[25];
vector<int> tmp;

void f(int p) 
{
    if (p == n) {
        for (int i = 0; i < 26; i++) {
            if (!tmp[i]) break;
            if (i == 25) ans++;
        }
        return;
    }

    f(p + 1); int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (v[p][i]) tmp[i]++;
        if (tmp[i]) cnt++;
    }
    if (cnt == 26) {
        ans += pow(2, n - p - 1);
        for (int i = 0; i < 26; i++) {
            if (v[p][i]) tmp[i]--;
        }
        return;
    }
    else f(p + 1);
    for (int i = 0; i < 26; i++) {
        if (v[p][i]) tmp[i]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; tmp.resize(26);
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            v[i][str[j]-'a'] = true;
            tmp[str[j]-'a']++;
        }
    }

    bool ok = true;

    for (int i = 0; i < 26; i++) {
        if (!tmp[i]) ok = false;
        tmp[i] = 0;
    }
    if (!ok) { cout << 0 << '\n'; return 0; }

    f(0);

    cout << ans << '\n';

    return 0;
}