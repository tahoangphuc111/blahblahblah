#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll sum = 1LL * n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    }
    vector<int> a, b;
    ll need = sum / 2;
    for (int i = n; i >= 1; i--) {
        if (need >= i) {
            a.push_back(i);
            need -= i;
        } 
        else {
            b.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
    cout << b.size() << endl;
    for (int x : b) {
        cout << x << ' ';
    }

    return 0;
}