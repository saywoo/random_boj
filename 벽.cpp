#include <bits/stdc++.h>
using namespace std;

int n, k, tmp;
vector<int> st, lazy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (tmp = 1; tmp < n; tmp *= 2) {}
    st.resize(tmp * 2); lazy.resize(tmp * 2);

    return 0;
}