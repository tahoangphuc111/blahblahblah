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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> v, c;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] != a[i - 1]) {
                v.push_back(a[i]);
                c.push_back(1);
            } 
            else {
                c.back()++;
            }
        }
        int m = v.size();
        vector<int> g(m + 1, 0), p(m + 1, 0), jl(m + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            int r = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
            if (p[i + 1] - p[r] > 0) {
                jl[i] = 1;
            }
            if (jl[i] == 0 && c[i] % 2 == 1) {
                g[i] = 1;
            }
            p[i] = g[i] + p[i + 1];
        }
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            if (jl[i] == 1 || c[i] % 2 == 0) {
                ok = true;
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