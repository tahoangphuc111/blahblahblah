// code by tahoangphuc111


// 1087C - Find the Zero
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    auto q = [&](int i, int j) {
        cout << "? " << i << " " << j << endl;
        int r;
        cin >> r;
        if (r == -1) { 
            exit(0);
        }
        return r;
    };
    if (q(1, 2)) { 
        cout << "! 1" << endl;
        return; 
    }
    if (q(2, 3)) { 
        cout << "! 2" << endl; 
        return; 
    }
    if (q(3, 1)) { 
        cout << "! 3" << endl; 
        return; 
    }
    for (int i = 1; i <= n - 2; i++) {
        int u = 2 * i + 2;
        int v = 2 * i + 3;
        if (q(u, v)) { 
            cout << "! " << u << endl; 
            return; 
        }
    }
    cout << "! " << 2 * n << endl;
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