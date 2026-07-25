#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void hanoi(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << a << ' ' << b << endl;
    hanoi(n - 1, c, b, a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}