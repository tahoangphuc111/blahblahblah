#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> gu(int x, int n) {
    vector<bool> v(n, false);
    int i = 0;
    while (x > 0) {
        if (x & 1) v[i] = true;
        i++;
        x >>= 1;
    }
    return v;
}
ll calc(vector<pair<ll,ll>> a, vector<bool> b) {
    ll s = 1, t = 0;
    for (int i = 0; i < a.size(); i++) {
        if (b[i]) {
            s *= a[i].first;
            t += a[i].second;
        }
    }
    return abs(t - s);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PERKET.INP", "r", stdin);
    freopen("PERKET.OUT", "w", stdout);
    int n; 
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll ans = 1e18;
    for (int i = 1; i < pow(2, n); i++) {
        vector<bool> u = gu(i, n);
        ans = min(ans, calc(a, u));
    }
    cout << ans;
    return 0;
}