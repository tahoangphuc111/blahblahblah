//Skocimis problem statement: https://www.spoj.com/problems/SKOCIMIS/



#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SKOCIMIS.INP", "r", stdin);
    freopen("SKOCIMIS.OUT", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({b - a, c - b}) - 1;
    return 0;
}