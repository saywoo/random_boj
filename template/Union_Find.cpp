#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> parent;

void init() { for (int i = 1; i <= n; i++) parent[i] = i; }
int Find(int x) { return (x == parent[x]) ? x : parent[x] = Find(parent[x]); }
void Union(int x, int y) { if (Find(x) != Find(y)) parent[Find(x)] = Find(y); }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    parent.resize(n + 1);

    init();
    Union(1, 3);
    cout << Find(1) << " " << Find(3) << '\n';

    return 0;
}