#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int LOG = 32;

void dfs(int node, int p, vector<int>& par, vector<int>& h,
         vector<vector<int>>& adj, vector<int>& order) {
    order.push_back(node);
    par[node] = p;
    if (p != -1) h[node] = h[p] + 1;
    for (auto u : adj[node]) {
        if (u == p) continue;
        dfs(u, node, par, h, adj, order);
    }
}

int get_dist(int a, int b, vector<vector<int>>& lift, vector<int>& h) {
    int retval = 0;
    if (h[a] < h[b]) swap(a, b);
    int x = a, y = b;
    int d = h[a] - h[b];
    for (int i = 0; (1LL << i) <= d; i++) {
        if (d & (1LL << i)) a = lift[a][i];
    }
    int ans = 0;
    for (int jump = LOG - 1; jump >= 0; jump--) {
        if (lift[a][jump] == -1) continue;
        if (lift[a][jump] != lift[b][jump]) {
            a = lift[a][jump];
            b = lift[b][jump];
        }
    }
    ans = lift[a][0];
    if (a == b) ans = a;
    retval = h[x] - h[ans] + h[y] - h[ans];
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> lift(n, vector<int>(LOG, -1));
    vector<int> order;
    vector<int> p(n, -1);
    vector<int> h(n, 0);
    dfs(0, -1, p, h, adj, order);
    for (int i = 0; i < n; i++) lift[i][0] = p[i];
    for (int i = 0; i < n; i++) {
        int cur = order[i];
        for (int exp = 1; exp < LOG; exp++)
            if (lift[cur][exp - 1] != -1)
                lift[cur][exp] = lift[lift[cur][exp - 1]][exp - 1];
    }
    for (int query = 0; query < q; query++) {
        int k;
        scanf("%lld", &k);
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            scanf("%lld", &a[i]);
            a[i]--;
        }
        if (k == 1) {
            printf("0\n");
            continue;
        }
        int f = a[0], s = a[1];
        int dist = get_dist(f, s, lift, h);
        for (int i = 2; i < k; i++) {
            int v1 = get_dist(a[i], f, lift, h);
            int v2 = get_dist(a[i], s, lift, h);
            if (v1 > dist || v2 > dist) {
                if (v1 > v2) {
                    s = a[i];
                    dist = v1;
                } else {
                    f = a[i];
                    dist = v2;
                }
            }
        }
        int ans = dist / 2;
        if (dist & 1) ans++;
        printf("%lld\n", ans);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
