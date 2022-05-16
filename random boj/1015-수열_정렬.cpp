#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n;
vector<pr> v;
vector<int> ans;

bool cmp(pr x, pr y)
{
    if (x.A == y.A) return x.B < y.B;
    else return x.A < y.A;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n); ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].A; v[i].B = i;
    } 

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) ans[v[i].B] = i;

    for (int i: ans) cout << i << " ";

    return 0;
}