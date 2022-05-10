#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int n, tmp;
vector<int> v, w(MAX), ans;
stack<int> s;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n); ans.resize(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        w[v[i]]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        while (s.size()) {
            if (w[v[i]] < w[s.top()]) {
                ans[i] = s.top();
                break;
            }
            else s.pop();
        }

        s.push(v[i]);
    }

    for (int i: ans) cout << i << " ";

    return 0;
}