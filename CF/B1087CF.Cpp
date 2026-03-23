// code by tahoangphuc111
// 1087B - Array


#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        int g = 0, l = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                g++;
            } 
            else if (a[j] < a[i]) {
                l++;
            }
        }
        cout << max(g, l) << " ";
    }
    cout << endl;
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