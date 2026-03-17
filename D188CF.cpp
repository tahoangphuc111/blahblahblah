// Educational Codeforces Round 188 (Rated for Div. 2) - Problem D





#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector<int> c(n + 1, -1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == -1) {
                int c0 = 0, c1 = 0;
                bool ok = 1;
                queue<int> q;
                q.push(i);
                c[i] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    if (c[u] == 0) {
                        c0++;
                    }
                    else {
                        c1++;
                    }
                    for (int v : a[u]) {
                        if (c[v] == -1) {
                            c[v] = c[u] ^ 1;
                            q.push(v);
                        } 
                        else if (c[v] == c[u]) {
                            ok = 0;
                        }
                    }
                }
                if (ok) {
                    ans += max(c0, c1);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}





