#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;

    string str = "";

    while (str.length() < 6) {
        str = str + s;
    } 

    cout << str << '\n';

    return 0;
}