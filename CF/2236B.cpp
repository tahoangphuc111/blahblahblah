#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> c(k, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            c[i % k]++;
        }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
        if (c[i] % 2 != 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "YES" << endl;
    } 
    else {
        cout << "NO"<< endl;
    }
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