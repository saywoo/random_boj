#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef long long int ll;
typedef pair<ll, ll> pr;
ll t, n, k, m, tmp, b, c, d;
vector<ll> v, st, ss, l_st;
vector<pr> q;

void lazy(int s, int e, int p)
{
    st[p] += l_st[p] * (e - s + 1);
    if (s != e) {
        l_st[p*2] += l_st[p]; l_st[p*2+1] += l_st[p];
    }
    l_st[p] = 0;
}

void Range_Update(int s, int e, int p)
{
    if (l_st[p]) lazy(s, e, p);

    if (e < b || c < s) return;
    else if (b <= s && e <= c) {
        l_st[p] = d;
        lazy(s, e, p);
        return;
    }
    else {
        Range_Update(s, (s + e) / 2, p * 2);
        Range_Update((s + e) / 2 + 1, e, p * 2 + 1);
        st[p] = st[p*2] + st[p*2+1];
    }
}

ll Print(int s, int e, int p)
{
    if (l_st[p]) lazy(s, e, p);
    if (e < b || c < s) return 0;
    else if (b <= s && e <= c) return st[p];
    else return Print(s, (s + e) / 2, p * 2) + Print((s + e) / 2 + 1, e, p * 2 + 1);
}

void Update(int p)
{
    p = p + tmp - 1;
    ss[p] = 0;

    while (p != 1) {
        p /= 2;
        ss[p] = ss[p*2] + ss[p*2+1];
    }
}

int ans(int s, int e, int p)
{
    if (c < s || e < b) return 0;
    else if (b <= s && e <= c) return ss[p];
    else return ans(s, (s + e) / 2, p * 2) + ans((s + e) / 2 + 1, e, p * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> k; 
        v.resize(n); ll Sum = 0;
        for (tmp = 1; tmp < n; tmp *= 2) {}
        ss.resize(tmp * 2, 1); st.resize(tmp * 2); l_st.resize(tmp * 2);
        for (int i = 0; i < n; i++) {
            cin >> m; Sum += m;
            q.push_back({m, i + 1});
        }

        for (int i = tmp - 1; i; i--) ss[i] = ss[i*2] + ss[i*2+1];

        sort(q.begin(), q.end(), greater<>());

        for (int i = 0; i < k; i++) {
            b = q[i].B; c = q[i].B;
            q[i].A += Print(1, tmp, 1);

            b = q[i].B + 1; c = n; d = 1;
            int temp = ans(1, tmp, 1);
            int rev = n - q[i].B - temp;
            if (temp - rev > q[i].A) break; 
            Range_Update(1, tmp, 1);
            Sum -= q[i].A; Sum -= rev;
            Update(q[i].B);
        }

        b = 1; c = n;

        cout << Sum + Print(1, tmp, 1) << '\n';

        v.clear(); st.clear(); ss.clear(); l_st.clear(); q.clear();
    }

    return 0;
}