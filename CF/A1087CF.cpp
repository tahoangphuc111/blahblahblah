// code by tahoangphuc111
// 1087A - Flip Flops


#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, c, k;
    cin >> n >> c >> k;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] <= c) {
            long long x = min(k, c - a[i]);
            k -= x;
            c += a[i] + x;
        } 
        else {
            break;
        }
    }
    cout << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}