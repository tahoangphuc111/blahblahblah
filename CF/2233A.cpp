#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, x, y, z;
        cin >> n >> x >> y >> z;
        ll a1 = (n + x + y - 1) / (x + y);
        ll a2;
        if (z * x >= n) {
            a2 = (n + x - 1) / x;
        }
        else {
            ll r = n - z * x;
            ll s = x + 10 * y;
            a2 = z + (r + s - 1) / s; 
        }
        cout << min(a1, a2) << endl;
    }
    return 0;
}