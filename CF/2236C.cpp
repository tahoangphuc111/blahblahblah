#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    map<ll, ll> va, vb;
    queue<ll> qa, qb;
    
    va[a] = 0;
    qa.push(a);
    while (!qa.empty()) {
        ll u = qa.front();
        qa.pop();
        ll d = va[u];
        ll nu = u / x;
        if(va.find(nu) == va.end()) {
            va[nu] = d + 1;
            qa.push(nu);
        }
    }
    vb[b] = 0;
    qb.push(b);
    while (!qb.empty()) {
        ll u = qb.front();
        qb.pop();
        ll d = vb[u];
        ll nu = u / x;
        if (vb.find(nu) == vb.end()) {
            vb[nu] = d + 1;
            qb.push(nu);
        }
    }
    
    ll res = 2e18;
    for (auto& p : va) {
        ll val = p.first;
        ll da = p.second;
        auto it = vb.upper_bound(val);
        if (it != vb.begin()) {
            it--;
            ll vval = it->first;
            ll db = it->second;
            res = min(res, da + db + (val - vval));
        }
    }
    
    for (auto& p : vb) {
        ll val = p.first;
        ll db = p.second;
        auto it = va.upper_bound(val);
        if (it != va.begin()) {
            it--;
            ll vval = it->first;
            ll da = it->second;
            res = min(res, da + db + (val - vval));
        }
    }
    
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}