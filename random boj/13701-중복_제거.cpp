#include <bits/stdc++.h>
using namespace std;

int n;
bitset<33554433> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        if (!s[n]) { s[n] = true; cout << n << " "; } 
    }

    return 0;
}