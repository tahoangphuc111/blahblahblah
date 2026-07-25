#include <bits/stdc++.h>
using namespace std;

using ll = long long;


const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * 2 % MOD;
    }
    cout << ans;

    return 0;
}