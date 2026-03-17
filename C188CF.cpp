// Educational Codeforces Round 188 (Rated for Div. 2) - Problem C




#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll L(ll x, ll y) {
    __int128 l = (__int128)x / std::gcd(x, y) * y;
    if (l > 2e18) return 2e18;
    return (ll)l;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll na = m / a, nb = m / b, nc = m / c;
        ll ab = L(a, b), bc = L(b, c), ca = L(c, a), abc = L(ab, c);
        ll nab = m / ab, nbc = m / bc, nca = m / ca, nabc = m / abc;
        ll wa = 6 * na - 3 * nab - 3 * nca + 2 * nabc;
        ll wb = 6 * nb - 3 * nab - 3 * nbc + 2 * nabc;
        ll wc = 6 * nc - 3 * nbc - 3 * nca + 2 * nabc;
        cout << wa << " " << wb << " " << wc << "\n";
    }
    return 0;
}