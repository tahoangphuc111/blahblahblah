#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do {
        ans.push_back(s);
    } 
    while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << endl;
    for (string x : ans) {
        cout << x << endl;
    }
    return 0;
}