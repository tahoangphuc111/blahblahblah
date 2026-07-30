#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'A']++;
    }
    int odd = 0;
    char mid = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            odd++;
            mid = char('A' + i);
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    string left = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) {
            left += char('A' + i);
        }
    }
    string right = left;
    reverse(right.begin(), right.end());
    cout << left;
    if (mid != 0){ 
        }            
        }
    cout << right;
    return 0;
}