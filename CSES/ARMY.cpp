#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b /= 2;
    }

    return res;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("ARMY.INP", "r", stdin);
    freopen("ARMY.OUT", "w", stdout);

    ll m;
    int n;
    cin >> m >> n;

    ll f = 1;

    for (int i = 1; i <= n; i++) {
        f = f * i % MOD;
    }

    ll a = 1;
    ll b = 0;

    for (int i = 2; i <= n; i++) {
        ll c = 1LL * (i - 1) * (a + b) % MOD;
        a = b;
        b = c;
    }

    ll d = (n == 1 ? 0 : b);

    ll ans = f * pw(d, m - 1) % MOD;

    cout << ans << endl;

    return 0;
}