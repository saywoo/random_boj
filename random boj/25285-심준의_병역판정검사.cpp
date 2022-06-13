#include <bits/stdc++.h>
using namespace std;

int n;
double a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n--) {
        cin >> a >> b;
        if (a < 140.1) cout << 6 << '\n';
        else if (a < 146) cout << 5 << '\n';
        else if (a < 159) cout << 4 << '\n';
        else if (a < 161) {
            double bmi = b / (a / 100.0 * a / 100.0);
            if (bmi < 16.0) cout << 4 << '\n';
            else if (bmi < 35.0) cout << 3 << '\n';
            else cout << 4 << '\n';
        }
        else if (a < 204) {
            double bmi = b / (a / 100.0 * a / 100.0);
            if (bmi < 16.0) cout << 4 << '\n';
            else if (bmi < 18.5) cout << 3 << '\n';
            else if (bmi < 20.0) cout << 2 << '\n';
            else if (bmi < 25.0) cout << 1 << '\n';
            else if (bmi < 30.0) cout << 2 << '\n';
            else if (bmi < 35.0) cout << 3 << '\n';
            else cout << 4 << '\n';
        }
        else cout << 4 << '\n';
    }

    return 0;
}