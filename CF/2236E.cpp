#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sz = (n / 2 + 1) * (n + 1);
        vector<int> mn(sz, 1e9), mx(sz, -1e9);
        vector<int> v(n + 1, 0);
        int id = 0;
        for (int i = 0; i < n; ++i) {
            id++;
            int mi = a[i], ma = a[i];
            for (int j = i; j < n; ++j) {
                if (v[a[j]] == id) break;
                v[a[j]] = id;
                mi = min(mi, a[j]);
                ma = max(ma, a[j]);
                int l = j - i + 1;
                if (l <= n / 2 && ma - mi == l - 1) {
                    int k = l * (n + 1) + mi;
                    mn[k] = min(mn[k], j);
                    mx[k] = max(mx[k], i);
                }
            }
        }
        int ans = 0;
        for (int l = 1; l <= n / 2; ++l) {
            for (int val = 1; val + 2 * l - 1 <= n; ++val) {
                int k1 = l * (n + 1) + val;
                int k2 = l * (n + 1) + (val + l);
                if (mn[k1] < mx[k2] || mn[k2] < mx[k1]) {
                    ans = max(ans, l);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}