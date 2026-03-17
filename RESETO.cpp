#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RESETO.INP", "r", stdin);
    freopen("RESETO.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<bool> used(n + 1, false);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!used[i]) {
            for (int j = i; j <= n; j += i) {
                if (!used[j]) {
                    used[j] = true;
                    cnt++;
                    if (cnt == k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}