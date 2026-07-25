#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int total = 1 << n;

    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);

        for (int bit = n - 1; bit >= 0; bit--) {
            cout << ((gray >> bit) & 1);
        }

        cout << endl;
    }

    return 0;
}