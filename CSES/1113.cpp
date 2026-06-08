#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> c(256, 0);
    for (char x : s) {
        c[x]++;
    }
    int h = 0;
    for (int i = 0; i < 256; i++) {
        int t = c[i];
        c[i] = h;
        h += t;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[c[s[i]]++] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            k = i;
            break;
        }
    }
    string ans(n - 1, ' ');
    for (int i = 0; i < n; i++) {
        k = p[k];
        ans[i] = s[k];
    }
    cout << ans << endl;
    return 0;
}