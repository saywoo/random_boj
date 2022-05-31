#include <bits/stdc++.h>
using namespace std;

int n, k, tmp, a, b, c, d;
vector<int> st, lazy;

void pp_Update(int l, int r, int s, int e, int p, int N) 
{

}

void mm_Update(int l, int r, int s, int e, int p, int N)
{
    if ()
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (tmp = 1; tmp < n; tmp *= 2) {}
    st.resize(tmp * 2); lazy.resize(tmp * 2);

    while (k--) {
        cin >> a >> b >> c >> d;

        // plus query
        if (a == 1) {
            pp_Update(1, tmp, b, c, 1, d);
        }
        // minus query
        else {
            mm_Update(1, tmp, b, c, 1, d);
        }
    }

    return 0;
}