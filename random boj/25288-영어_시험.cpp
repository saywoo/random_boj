#include <bits/stdc++.h>
using namespace std;

int n;
string str;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> str;
    sort(str.begin(), str.end());

    for (int i = 0; i < n; i++) cout << str;

    return 0;
}