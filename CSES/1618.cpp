#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll ans = 0;
    for (ll p = 5; p <= n; p *= 5) {
        ans += n / p;
    }
    cout << ans;
    return 0;
}