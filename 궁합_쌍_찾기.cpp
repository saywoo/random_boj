#include <bits/stdc++.h>
using namespace std;

int v[15], cnt = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> v[cnt++]) {}
    for (int i = 0; i < cnt; i++) cout << v[i] << '\n';

    return 0;
}