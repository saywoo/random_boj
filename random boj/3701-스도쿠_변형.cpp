#include <bits/stdc++.h>
using namespace std;

int t, x[9][10], y[9][10], block[9][10], f[10], ans_mark[2][10][10], prob_mark[2][10][10], visited[10];
int visited_x[10], visited_y[10];
vector<string> ans(9), prob(9), temp(9);
string s;
bool ok;

// 
int block_ret(int a, int b)
{
    if (b >= 6) {
        if (a >= 6) return 8;
        else if (a >= 3) return 7;
        else return 6;
    }
    else if (b >= 3) {
        if (a >= 6) return 5;
        else if (a >= 3) return 4;
        else return 3;
    }
    else {
        if (a >= 6) return 2;
        else if (a >= 3) return 1;
        else return 0;
    }
}

void func(int a, int b)
{
    if (b == 9) {
        a++; b = 0;
    }
    if (a == 9) {
        for (int i = 0; i < 9; i++) temp[i] = prob[i];
        return;
    }

    if (prob[a][b] != '0') {
        func(a, b + 1); 
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!x[a][i] && !y[b][i] && !block[block_ret(a, b)][i]) {
            x[a][i] = 1; y[b][i] = 1; block[block_ret(a, b)][i] = 1;
            prob[a][b] = (char)('0' + i);
            func(a, b + 1);
            prob[a][b] = '0';
            x[a][i] = 0; y[b][i] = 0; block[block_ret(a, b)][i] = 0;
        }
    }
}

void ans_tracking(int pos)
{
    if (pos == 10) {
        ok = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!visited[i]) {
            int bu_x[10], bu_y[10];

            bool flag = true;

            for (int a = 0; a < 9; a++) {
                bu_x[a] = visited_x[a];
                bu_y[a] = visited_y[a];
            }
            for (int a = 0; a < 9; a++) {
                if (visited_x[prob_mark[0][a][i]] == -1) {
                    visited_x[prob_mark[0][a][i]] = ans_mark[0][a][pos];
                }
                else {
                    if (visited_x[prob_mark[0][a][i]] != ans_mark[0][a][pos]) {
                        flag = false;
                    }
                }

                if (visited_y[prob_mark[1][a][i]] == -1) {
                    visited_y[prob_mark[1][a][i]] = ans_mark[1][a][pos];
                }
                else {
                    if (visited_y[prob_mark[1][a][i]] != ans_mark[1][a][pos]) {
                        flag = false;
                    }
                }
            }

            if (flag) {
                visited[i] = true;
                ans_tracking(pos + 1);
                visited[i] = false;
            }

            for (int a = 0; a < 9; a++) {
                visited_x[a] = bu_x[a];
                visited_y[a] = bu_y[a];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        ok = false;

        for (int i = 0; i < 9; i++) cin >> ans[i];

        for (int i = 0; i < 9; i++) {
            cin >> prob[i];
            for (int j = 0; j < 9; j++) {
                if (prob[i][j] == '0') continue;
                x[i][prob[i][j]-'0'] = 1;
                y[j][prob[i][j]-'0'] = 1;
                block[block_ret(i, j)][prob[i][j]-'0'] = 1;
            }
        }

        for (int a = 0; a < 9; a++) {
            for (int b = 0; b < 9; b++) {
                ans_mark[0][block_ret(a, b)][ans[a][b]-'0'] = a;
                ans_mark[1][block_ret(a, b)][ans[a][b]-'0'] = b;
            }
        }

        func(0, 0);

        for (int i = 0; i < 9; i++) prob[i] = temp[i];

        // 1번 연산
        for (int i = 0; i < 2; i++) {
            // 2번 연산
            for (int j = 0; j < 6; j++) {
                // 3번 연산
                for (int k = 0; k < 6; k++) {

                    for (int a = 0; a < 9; a++) {
                        for (int b = 0; b < 9; b++) {
                            prob_mark[0][block_ret(a, b)][prob[a][b]-'0'] = a;
                            prob_mark[1][block_ret(a, b)][prob[a][b]-'0'] = b;
                        }
                    }

                    for (int i = 0; i < 10; i++) {
                        visited_x[i] = -1;
                        visited_y[i] = -1;
                    }

                    ans_tracking(1);

                    for (int b = 0; b < 9; b++) {
                        for (int a = 0; a < 3; a++) {
                            if (k & 1) {
                                char ch = prob[b][a];
                                prob[b][a] = prob[b][a+6];
                                prob[b][a+6] = ch;
                            }
                            else {
                                char ch = prob[b][a];
                                prob[b][a] = prob[b][a+3];
                                prob[b][a+3] = ch;
                            }
                        }
                    }
                }

                for (int a = 0; a < 3; a++) {
                    if (j & 1) {
                        s = prob[a];
                        prob[a] = prob[a+6];
                        prob[a+6] = s;
                    }
                    else {
                        s = prob[a];
                        prob[a] = prob[a+3];
                        prob[a+3] = s;
                    }
                }
            }

            for (int a = 0; a < 9; a++) {
                for (int b = 0; b < 9; b++) temp[a][b] = prob[b][8-a];
            }
            for (int a = 0; a < 9; a++) prob[a] = temp[a];
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 1; j <= 9; j++) {
                x[i][j] = 0; 
                y[i][j] = 0; 
                block[i][j] = 0;
            }
        }

        if (ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
} 