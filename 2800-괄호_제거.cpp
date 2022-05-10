#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> ans;
vector<int> s, e;
stack<int> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> str;
    n = str.length(); int cnt = 0; int siz = 0; 
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') { 
            stk.push(i);
            siz++; 
        }
        else if (str[i] == ')') {
            s.push_back(stk.top());
            e.push_back(i);
            stk.pop();
        }
    }

    for (int i = 1; i < pow(2, siz); i++) {
        string tmp = "";

        for (int j = 0; j < n; j++) {
            bool ok = true;
            for (int k = 0; k < siz; k++) {
                if ((1 << k) & i) {
                    if (j == s[k]) ok = false;
                    if (j == e[k]) ok = false;
                }
            }

            if (!ok) continue;
            else tmp = tmp + str[j];
        }

        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto i: ans) cout << i << '\n';
    return 0;
}