#include <bits/stdc++.h>
using namespace std;

int t;
string b;
double a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout.setf(ios::fixed);
    cout.precision(4);

    cin >> t;

    while (t--) {
        cin >> a >> b;

        if (b == "kg") {
            cout << a * 2.2046 << " lb" << '\n';
        }
        else if (b == "lb") {
            cout << a * 0.4536 << " kg" << '\n';
        }
        else if (b == "l") {
            cout << a * 0.2642 << " g" << '\n';
        }
        else {
            cout << a * 3.7854 << " l" << '\n'; 
        }
    }

    return 0;
}