#include <bits/stdc++.h>
using namespace std;

#define ctoi(c) (c - '0')
int t;
char gen;
string f, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> gen >> f >> m;

        int a, b, s, l, r;

        if (f.length() == 4) a = ctoi(f[0]) * 12 + ctoi(f[2]);
        else a = ctoi(f[0]) * 12 + ctoi(f[2]) * 10 + ctoi(f[3]);

        if (m.length() == 4) b = ctoi(m[0]) * 12 + ctoi(m[2]);
        else b = ctoi(m[0]) * 12 + ctoi(m[2]) * 10 + ctoi(m[3]);

        if (gen == 'B') s = a + b + 5;
        if (gen == 'G') s = a + b - 5;

        if (s & 1) {
            s /= 2;
            l = s - 3; r = s + 4;
        }
        else {
            s /= 2;
            l = s - 4; r = s + 4;
        }

        cout << "Case #" << i << ": " << l / 12 << "\'" << l % 12 << "\" to " << r / 12 << "\'" << r % 12 << "\"" << '\n';
    }

    return 0;
}