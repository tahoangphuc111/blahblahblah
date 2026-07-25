#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll ans = 0;
    ll prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        ll x;
        cin >> x;

        if (x < prev) {
            ans += prev - x;
        } 
        else {
            prev = x;
        }
    }

    cout << ans;

    return 0;
}