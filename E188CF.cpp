// Educational Codeforces Round 188 (Rated for Div. 2) - Problem E




#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        if (n == 1) {
            cout << s << "\n";
            continue;
        }
        int c[10] = {0};
        int sa = 0;
        for (int i = 0; i < n; i++) {
            c[s[i] - '0']++;
            sa += s[i] - '0';
        }
        for (int x = 1; x <= 9 * n; x++) {
            int v = x;
            string ts = "";
            int st = 0;
            while (1) {
                string sc = to_string(v);
                ts += sc;
                for (int i = 0; i < sc.length(); i++) {
                    st += sc[i] - '0';
                }
                if (v <= 9) break;
                int nx = 0;
                for (int i = 0; i < sc.length(); i++) {
                    nx += sc[i] - '0';
                }
                v = nx;
            }
            if (sa - st == x) {
                int ct[10] = {0};
                bool ok = true;
                for (int i = 0; i < ts.length(); i++) {
                    ct[ts[i] - '0']++;
                }
                for (int i = 0; i < 10; i++) {
                    if (ct[i] > c[i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    string r = "";
                    int rm[10];
                    for (int i = 0; i < 10; i++) {
                        rm[i] = c[i] - ct[i];
                    }
                    for (int i = 1; i < 10; i++) {
                        if (rm[i] > 0) {
                            r += char(i + '0');
                            rm[i]--;
                            break;
                        }
                    }
                    for (int i = 0; i < 10; i++) {
                        while (rm[i] > 0) {
                            r += char(i + '0');
                            rm[i]--;
                        }
                    }
                    r += ts;
                    cout << r << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}




