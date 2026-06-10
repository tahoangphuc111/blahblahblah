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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int u = vals.size();
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        }
        vector<int> v, l, r;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                v.push_back(a[i]);
                l.push_back(i);
                r.push_back(i);
            } 
            else {
                r.back() = i;
            }
        }
        int c = v.size();
        if (c == u) {
            cout << "YES" << endl;
            continue;
        }
        if (c - u > 4) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> bcnt(u, 0);
        for (int x : v) bcnt[x]++;
        vector<int> cand;
        for (size_t i = 0; i < v.size(); i++) {
            if (bcnt[v[i]] > 1) {
                cand.push_back(l[i]);
                cand.push_back(r[i]);
                if (l[i] > 0) {
                    cand.push_back(l[i] - 1);
                }
                if (r[i] < n - 1) {
                    cand.push_back(r[i] + 1);
                }
            }
        }
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        vector<int> vis(u, 0);
        int vid = 0;
        auto check = [&]() {
            vid++;
            int last = -1;
            for (int x : a) {
                if (x != last) {
                    if (vis[x] == vid) {
                        return false;
                    }
                    vis[x] = vid;
                    last = x;
                }
            }
            return true;
        };
        bool ok = false;
        for (size_t i = 0; i < cand.size(); i++) {
            for (size_t j = i + 1; j < cand.size(); j++) {
                swap(a[cand[i]], a[cand[j]]);
                if (check()) {
                    ok = true;
                    break;
                }
                swap(a[cand[i]], a[cand[j]]);
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}