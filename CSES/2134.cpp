#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 200005;
int n, q;
int v[maxn];
vector<int> adj[maxn];
int par[maxn], d[maxn], hv[maxn], hd[maxn], p[maxn], sz[maxn];
int cur = 1;
int seg[4 * maxn];

int dfs1(int u, int pr) {
    int s = 1;
    int mx = 0;
    par[u] = pr;
    d[u] = (pr == 0 ? 0 : d[pr] + 1);
    for (int c : adj[u]) {
        if (c != pr) {
            int cs = dfs1(c, u);
            s += cs;
            if (cs > mx) {
                mx = cs;
                hv[u] = c;
            }
        }
    }
    sz[u] = s;
    return s;
}

void dfs2(int u, int h) {
    hd[u] = h;
    p[u] = cur++;
    if (hv[u] != 0) {
        dfs2(hv[u], h);
    }
    for (int c : adj[u]) {
        if (c != par[u] && c != hv[u]) {
            dfs2(c, c);
        }
    }
}

void up(int node, int start, int end, int idx, int vl) {
    if (start == end) {
        seg[node] = vl;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        up(2 * node, start, mid, idx, vl);
    }
    else {
        up(2 * node + 1, mid + 1, end, idx, vl);
    }
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return seg[node];
    }
    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++) {
        up(1, 1, n, p[i], v[i]);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            up(1, 1, n, p[s], x);
        }
        else {
            int a, b;
            cin >> a >> b;
            int ans = 0;
            while (hd[a] != hd[b]) {
                if (d[hd[a]] > d[hd[b]]) {
                    swap(a, b);
                }
                ans = max(ans, query(1, 1, n, p[hd[b]], p[b]));
                // phai khong nhi, chac vay:v
                b = par[hd[b]];
            }
            if (d[a] > d[b]) {
                swap(a, b);
            }
            ans = max(ans, query(1, 1, n, p[a], p[b]));
            cout << ans << endl;
        }
    }
}