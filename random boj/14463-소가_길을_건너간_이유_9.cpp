#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans, tmp;
vector<int> v, visited, st;

void Update(int p, int num)
{
    st[p] = num;

    while (p != 1) {
        p /= 2;
        st[p] = st[p*2] + st[p*2+1];
    }
}

int Query(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return st[p];
    else return Query(l, (l + r) / 2, s, e, p * 2) + Query((l + r) / 2 + 1, r, s, e, p * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;

    v.resize(2 * n); visited.resize(n + 1, -1);
    for (tmp = 1; tmp < n * 2; tmp *= 2) {}
    st.resize(tmp * 2);
    for (int i = 0; i < 2 * n; i++) cin >> v[i];

    for (int i = 0; i < 2 * n; i++) {
        if (visited[v[i]] == -1) {
            visited[v[i]] = i + 1;
            Update(tmp + i, 1);
        }
        else {
            Update(tmp + visited[v[i]] - 1, -1);
            Update(tmp + i, 1);
            ans += Query(1, tmp, visited[v[i]], i + 1, 1);
        }
    }

    cout << ans / 2 << '\n';
    return 0;
}