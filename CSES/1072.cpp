#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (ll k = 1; k <= n; k++) {
        ll total = k * k * (k * k - 1) / 2;
        ll attack = 4 * (k - 1) * (k - 2);
        cout << total - attack << endl;
    }

    return 0;
}