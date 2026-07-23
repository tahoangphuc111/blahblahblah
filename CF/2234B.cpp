#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll p(ll x, ll l) {
    ll r = x, t = x;
    if (l % 2 != 0) {
        t /= 10;
    }
    while (t > 0) {
        r = r * 10 + (t % 10);
        t /= 10;
    }
    return r;
}

bool pal(ll n) {
    ll r = 0, t = n;
    while (t > 0) {
        r = r * 10 + (t % 10);
        t /= 10;
    }
    return r == n;
}

void solve() {
    ll n;
    cin >> n;
    if (n <= 1000) {
        for (ll a = n; a >= 0; --a) {
            if(pal(a) && (n - a) % 12 == 0) {
                cout << a << " " << n - a << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }
    string s = to_string(n);
    int l = s.length();
    int lenx = (l + 1) / 2;
    ll x0 = stoll(s.substr(0, lenx));
    if (p(x0, l) > n) {
        x0--;
    }
    ll cx = x0;
    bool f = true;
    while (cx > 0) {
        ll p10 = 1;
        for (int i = 0; i < lenx - 2; ++i) {
            p10 *= 10;
        }
        ll pr = cx /p10;
        ll top = f ? cx : (pr * p10 + p10 - 1);
        f = false;
        for (ll x = top; x >= pr * p10 && x >= top - 2; --x) {
            ll v = p(x, l);
            if ((n - v) % 12 == 0) {
                cout << v << " " << n - v << endl;
                return;
            }
        }
        cx = pr * p10 - 1;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}