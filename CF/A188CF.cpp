// Educational Codeforces Round 188 (Rated for Div. 2) - Problem A



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
        string s;
        cin >> n >> s;
        set<int> v;
        int u = 0;
        v.insert(u);
        for (int i = 0; i < n; i++) {
            u += (s[u] == 'R' ? 1 : -1);
            v.insert(u);
        }
        cout << v.size() << "\n";
    }
    return 0;
}