#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> p;
    vector<int> st;
    vector<bool> m(n, false);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push_back(i);
        } 
        else {
            if (!st.empty()) {
                int l = st.back();
                st.pop_back();
                p.push_back({l, i});
                m[l] = true;
                m[i] = true;
            }
        }
    }
    int lf = n;
    for (int i = 0; i < n; ++i) {
        if (!m[i] && s[i] == '(') {
            lf = i;
            break;
        }
    }
    vector<int> cand;
    for (auto& pr : p) {
        if (pr.first < lf) {
            cand.push_back(pr.first);
        } 
        else {
            cand.push_back(pr.second);
        }
    }
    string ans(n, '0');
    int limit = min((int)p.size(), k);
    for (int i = 0; i < limit; ++i) {
        ans[cand[i]] = '1';
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