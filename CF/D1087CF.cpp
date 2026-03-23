// code by tahoangphuc111


// 1087D - Ghostfires

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    int c[3] = {r, g, b};
    string s = "";
    while (1) {
        int p = -1;
        for (int i = 0; i < 3; i++) {
            if (c[i] == 0) {
                continue;
            }
            if (s.size() >= 1 && s.back() == "RGB"[i]) {
                continue;
            }
            if (s.size() >= 3 && s[s.size() - 3] == "RGB"[i]) {
                continue;
            }
            if (p == -1) {
                p = i;
            } 
            else {
                bool b1 = (s.size() >= 2 && s[s.size() - 2] == "RGB"[i]);
                bool b2 = (s.size() >= 2 && s[s.size() - 2] == "RGB"[p]);
                if (c[i] > c[p] || (c[i] == c[p] && b1 > b2)) { 
                    p = i;
                }
            }
        }
        if (p == -1) {
            break;
        }
        s += "RGB"[p];
        c[p]--;
    }
    cout << s << endl;
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