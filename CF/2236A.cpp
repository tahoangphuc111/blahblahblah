#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        mx = max(mx, h[i]);
    }
    int res = mx - h[0] + 1;
    for (int i = 1; i < n; i++) {
        res = max(res, mx - h[i] + 1);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}