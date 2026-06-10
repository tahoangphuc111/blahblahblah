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
        int n;
        cin >> n;
        vector<int> a(4 * n);
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
            a[n + i] = n - i;
            a[2 * n + i] = n - i;
            a[3 * n + i] = i + 1;
        }
        if (n % 2 != 0) {
            int m = (n + 1) / 2;
            swap(a[2 * n - m], a[2 * n - 1]);
            swap(a[3 * n - m], a[3 * n - 1]);
        }
        for (int i = 0; i < 4 * n; ++i) {
            cout << a[i] << (i == 4 * n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}