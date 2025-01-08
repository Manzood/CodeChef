#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

pair<int, int> dfs(int node, int par, int target, int mask,
                   vector<vector<int>>& adj, vector<int>& a) {
    pair<int, int> retval = {0, 0};
    retval.first ^= a[node] & (target | mask);
    for (auto u : adj[node]) {
        if (u != par) {
            pair<int, int> temp = dfs(u, node, target, mask, adj, a);
            retval.first ^= temp.first;
            retval.second += temp.second;
        }
    }
    if ((retval.first & (mask | target)) == (mask | target)) {
        retval.first = 0;
        retval.second++;
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mask = 0;
    for (int i = 29; i >= 0; i--) {
        int target = 1LL << i;
        pair<int, int> tmp = dfs(0, -1, target, mask, adj, a);
        if (tmp.first == 0 && tmp.second >= k && (tmp.second - k) % 2 == 0) {
            mask |= target;
        }
    }
    printf("%lld\n", mask);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
