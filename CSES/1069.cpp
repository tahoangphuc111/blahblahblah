#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int ans = 1;
    int cnt = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } 
        else {
            cnt = 1;
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}