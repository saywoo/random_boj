#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
ll n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    ll low = -1; ll high = (1ULL << 32) - 1;

    while (low + 1 < high) {
        ll mid = (low + high) / 2;

        if (mid * mid >= n) high = mid;
        else low = mid;
    }

    cout << high << '\n';

    return 0;
}