#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> v;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    v.push_back(0); v.push_back(l);

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++) pq.push(v[i+1] - v[i]);

    while (m--) {
        // cout << pq.top() << '\n';
        int tmp = pq.top();
        pq.pop();
        
        pq.push(tmp / 2);
        if (tmp % 2) pq.push(tmp / 2 + 1);
        else pq.push(tmp / 2);
    }

    cout << pq.top() << '\n';

    return 0;
}