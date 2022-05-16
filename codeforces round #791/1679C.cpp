#include <bits/stdc++.h>
using namespace std;

int n, q, a, b, c, d, f, tmp;
vector<int> xst, yst, x, y;

void upx(int p)
{
    int pos = p + tmp - 1;
    if (x[p]) xst[pos] = 1;
    else xst[pos] = 0;

    while (pos != 1) {
        pos /= 2;
        xst[pos] = xst[pos*2] + xst[pos*2+1];
    }
}

void upy(int p)
{
    int pos = p + tmp - 1;
    if (y[p]) yst[pos] = 1;
    else yst[pos] = 0;

    while (pos != 1) {
        pos /= 2;
        yst[pos] = yst[pos*2] + yst[pos*2+1];
    }
}

int sx(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return xst[p];
    else return sx(l, (l + r) / 2, s, e, p * 2) + sx((l + r) / 2 + 1, r, s, e, p * 2 + 1);
}

int sy(int l, int r, int s, int e, int p)
{
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return yst[p];
    else return sy(l, (l + r) / 2, s, e, p * 2) + sy((l + r) / 2 + 1, r, s, e, p * 2 + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (tmp = 1; tmp < n; tmp *= 2) {}
    xst.resize(tmp * 2); yst.resize(tmp * 2); x.resize(n + 1); y.resize(n + 1);

    for (int i = 1; i <= q; i++) {
        cin >> a;

        if (a == 1) {
            cin >> b >> c;
            x[b]++; y[c]++;
            upx(b); upy(c);
        }
        else if (a == 2) {
            cin >> b >> c;
            x[b]--; y[c]--;
            upx(b); upy(c);
        }
        else {
            cin >> b >> c >> d >> f;

            int xx = sx(1, tmp, b, d, 1);
            int yy = sy(1, tmp, c, f, 1);

            if (xx < d - b + 1 && yy < f - c + 1) cout << "No" << '\n';
            else cout << "Yes" << '\n';
        }
    }

    return 0;
}