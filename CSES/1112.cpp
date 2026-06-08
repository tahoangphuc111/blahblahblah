#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int m = s.length();
    vector<int> p(m, 0);
    for (int i = 1; i < m; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    vector<vector<int>> nxt(m, vector<int>(26, 0));
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'A' + c != s[i]) {
                nxt[i][c] = nxt[p[i - 1]][c];
            } 
            else {
                nxt[i][c] = i + ('A' + c == s[i]);
            }
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (!dp[i][j]) {
                continue;
            }
            if (j == m) {
                dp[i + 1][m] = (dp[i + 1][m] + dp[i][j] * 26) % MOD;
            }
            else {
                for (int c = 0; c < 26; c++) {
                    int nxt_j = nxt[j][c];
                    dp[i + 1][nxt_j] = (dp[i + 1][nxt_j] + dp[i][j]) % MOD;
                }
            }
        }
    }   
    cout << dp[n][m] << endl;
    return 0;
}