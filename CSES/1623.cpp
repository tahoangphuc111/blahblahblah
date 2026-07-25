#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> p(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }
    ll ans = total;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum1 = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                sum1 += p[i];
            }
        }
        ll sum2 = total - sum1;
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans;
    return 0;
}