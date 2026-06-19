#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<bool> u(n, false);
    ll ans = 0;
    for (int j = 0; j < n; ++j) {
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (!u[i] && a[i] <= b[j]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            cout << -1 << endl;
            return;
        }
        u[idx] = true;
        for (int i = 0; i < idx; ++i) {
            if (!u[i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
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