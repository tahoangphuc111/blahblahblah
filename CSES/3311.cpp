#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> ans = a;
    string chars = "ABCD";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (char c : chars) {
                if (c == a[i][j]) {
                    continue;
                }
                if (i > 0 && c == ans[i - 1][j]) {
                    continue;
                }
                if (j > 0 && c == ans[i][j - 1]) {
                    continue;
                }
                ans[i][j] = c;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}