#include <bits/stdc++.h>
using namespace std;

vector<int> v(21);
int a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 20; i++) v[i] = i;

    for (int i = 1; i <= 10; i++) {
        cin >> a >> b;
        reverse(v.begin() + a, v.begin() + b + 1);
    }

    for (int i = 1; i <= 20; i++) cout << v[i] << " ";

    return 0;
}