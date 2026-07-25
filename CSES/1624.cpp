#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string> board(8);
bool col[8];
bool diag1[15];
bool diag2[15];
int ans = 0;

void solve(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') {
            continue;
        }
        if (col[c] || diag1[row + c] || diag2[row - c + 7]) {
            continue;
        }
        col[c] = true;
        diag1[row + c] = true;
        diag2[row - c + 7] = true;
        solve(row + 1);
        col[c] = false;
        diag1[row + c] = false;
        diag2[row - c + 7] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    solve(0);
    cout << ans;
    return 0;
}