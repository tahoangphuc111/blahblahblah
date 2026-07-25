#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        ll digits = 1;
        ll count = 9;
        ll start = 1;
        while (k > digits * count) {
            k -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        ll number = start + (k - 1) / digits;
        ll pos = (k - 1) % digits;
        string s = to_string(number);
        cout << s[pos] << endl;
    }
    return 0;
}