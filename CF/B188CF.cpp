// Educational Codeforces Round 188 (Rated for Div. 2) - Problem B



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = 0, c = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a >= m) {
                m = a;
                c++;
            }
        }
        cout << c << "\n";
    }
    return 0;
}