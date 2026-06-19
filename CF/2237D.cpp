#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n + 1, 0);
    vector<ll> c(3, 0);
    c[0] = 1;
    for (int i = 0; i < n; ++i) {
        p[i + 1] = (p[i] + (s[i] == '0' ? 1 : 2)) % 3;
        c[p[i + 1]]++;
    }
    ll ans = 1LL * n * (n + 1) / 2;
    for (int i = 0; i < 3; ++i) {
        ans -= c[i] * (c[i] - 1) / 2;
    }
    int len = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            len++;
        } 
        else {
            if (len >= 3) {
                if (len % 2 == 0) {
                    ans -= 1LL * (len / 2) * (len / 2 - 1);
                } 
                else {
                    ll m = (len - 1) / 2;
                    ans -= m * m;
                }
            }
            len = 1;
        }
    }
    if (len >= 3) {
        if (len % 2 == 0) {
            ans -= 1LL * (len / 2) * (len / 2 - 1);
        } 
        else {
            ll m = (len - 1) / 2;
            ans -= m * m;
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