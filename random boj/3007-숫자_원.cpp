#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m;
vector<int> num, x;
vector<vector<pr>> v;
vector<bool> visited;

void dfs(int p, int N)
{
    x[p] = N;
    visited[p] = true;

    for (pr i: v[p]) {
        if (!visited[i.A]) dfs(i.A, N + i.B);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    if (n % 3 == 0) {
        if (n == 3) {
            cin >> m;
            cout << m - 2 << '\n' << 1 << '\n' << 1 << '\n';
            for (int i = 0; i < 2; i++) {
                cin >> m;
            }
        }
        else {
            num.resize(n);
            for (int i = 0; i < n; i++) cin >> num[i];

            int a = 0; int b = 0; int c = 0; int ma = 0; int mb = 0;

            for (int i = 1; i < n - 2; i++) {
                int tmp = num[i+1] - num[i];
                if (i % 3 == 1) {
                    a += tmp; ma = min(a, ma);
                }
                else if (i % 3 == 2) {
                    b += tmp; mb = min(b, mb);
                }
            }

            a = ma * -1 + 1;
            b = mb * -1 + 1;
            c = num[1] - a - b;

            cout << a << '\n' << b << '\n' << c << '\n';

            for (int i = 1; i < n - 2; i++) {
                int tmp = num[i+1] - num[i];
                if (i % 3 == 1) {
                    a += tmp;
                    cout << a << '\n';
                }
                else if (i % 3 == 2) {
                    b += tmp;
                    cout << b << '\n';
                }
                else {
                    c += tmp;
                    cout << c << '\n';
                }
            }
        }

        return 0;
    }

    num.resize(n); v.resize(n + 1); visited.resize(n + 1); x.resize(n + 1);

    for (int i = 0; i < n; i++) cin >> num[i];

    int tmp = num[1] - num[0];
    v[3].push_back({n, -tmp});
    v[n].push_back({3, tmp});

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            int tmp = num[0] - num[i];
            v[(i+3)%n].push_back({i, -tmp});
            v[i].push_back({(i + 3) % n, tmp});
        }
        else {
            int tmp = num[i+1] - num[i];
            if (i == n - 3) {
                v[i+3].push_back({i, -tmp});
                v[i].push_back({i + 3, tmp});
            }
            else {
                v[(i+3)%n].push_back({i, -tmp});
                v[i].push_back({(i + 3) % n, tmp});
            }
        }
    }

    dfs(1, 0);

    tmp = num[1] - (x[1] + x[2] + x[3]);
    int X = tmp / 3;

    for (int i = 1; i <= n; i++) cout << X + x[i] << '\n';

    return 0;
}