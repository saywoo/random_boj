#include <bits/stdc++.h>
using namespace std;

struct tri {
    int a, b, num;
    bool operator<(const tri &t) const {
        if (a * t.b == t.a * b) return num < t.num;
        else return a * t.b < t.a * b;
    }
};
int n;
vector<tri> v;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n); ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
        v[i].num = i + 1;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) cout << v[i].num << " ";

    return 0;
}