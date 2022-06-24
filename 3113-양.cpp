#include <bits/stdc++.h>
using namespace std;

#define A first
#define B second
typedef pair<int, int> pr;
int n, m;
vector<int> v, cnt;
priority_queue<pr> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; v.resize(n); cnt.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> m;

    for (int i = 2; i <= 40000; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            cnt[j] = 0;
            while (v[j] % i == 0) {
                cnt[j]++; v[j] /= i;
                s++;
            }
        }

        if (s) {
            cout << "ENTER " << i << '\n';
            while (s) {
                int c = m;
                cout << "CLONE ";
                for (int j = 0; j < n; j++) {
                    if (cnt[j]) {
                        pq.push({cnt[j], (j + 1) * -1});
                    }
                }

                while (pq.size()) {
                    c--; s--;
                    cout << -pq.top().B << " ";
                    cnt[-pq.top().B - 1]--;
                    pq.pop();
                    if (!c) break;
                }

                cout << '\n';

                while (pq.size()) { pq.pop(); }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (v[i] != 1) {
            cout << "ENTER " << v[i] << '\n';
            int c = 0;
            
            for (int j = i; j < n; j++) {
                if (v[i] == v[j]) {
                    if (c && c % m == 0) cout << '\n'; 
                    if (c % m == 0) cout << "CLONE ";
                    cout << j + 1 << " ";
                    if (i != j) v[j] = 1; 
                    c++;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}