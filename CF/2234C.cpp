#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int s = 0; s < n; s++) {
        vector<ll> w1(n), w2(n), w(n);
        for (int i = 1; i < n; i++) {
            w1[(s + i) % n] = max(w1[(s + i - 1) % n], h[(s + i - 1) % n]);
        }
        for (int i = 1; i < n; i++) {
            w2[(s + n - i) % n] = max(w2[(s + n - i + 1) % n], h[(s + n - i + 1) % n]);
        }
        for (int i = 0; i < n; i++) {
            w[i] = min(w1[i], w2[i]);
        }
        cout << accumulate(w.begin(), w.end(), 011) << " ";
    }
    cout << endl;
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
}