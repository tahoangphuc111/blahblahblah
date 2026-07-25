#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok(vector<int>& cnt, int last, int rem) {
    int mx = 0;

    for (int i = 0; i < 26; i++) {
        mx = max(mx, cnt[i]);
    }

    if (mx > (rem + 1) / 2) {
        return false;
    }

    if (last != -1 && cnt[last] > rem / 2) {
        return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(26, 0);

    for (char c : s) {
        cnt[c - 'A']++;
    }

    if (!ok(cnt, -1, n)) {
        cout << -1;
        return 0;
    }

    string ans = "";
    int last = -1;

    for (int pos = 0; pos < n; pos++) {
        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0 || c == last) {
                continue;
            }
            cnt[c]--;
            if (ok(cnt, c, n - pos - 1)) {
                ans += char('A' + c);
                last = c;
                break;
            }
            cnt[c]++;
        }
    }
    cout << ans;
    return 0;
}