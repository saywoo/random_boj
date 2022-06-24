#include <bits/stdc++.h>
using namespace std;

int visited[26];
vector<int> a, b;

int findP(char T[], char P[], int N, int M)
{
    int cnt = 0; a.resize(N); b.resize(M);
    for (int i = 0; i < M; i++) {
        if (!visited[P[i]-'a']) {
            b[i] = cnt;
            visited[P[i]-'a'] = ++cnt;
        }
        else b[i] = visited[P[i]-'a'] - 1;
    }

    for (int i = 0; i < M; i++) cout << b[i];
    cout << '\n';

    return 1;
}


int main()
{
    char T[] = "abaababbab"; char P[] = "pqp";
    cout << findP(T, P, 9, 3) << '\n';

    return 0;
}