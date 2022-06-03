#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int inf = (int)1e9 + 7;

vector<vector <bool>> visited;
int dfs(int node, vector<vector<int>>& adj, vector<vector<int>>& dp, int color, vector<int>& a, vector<int>& b, int parent) {
    int retval = inf;
    if (visited[node][color]) return 0;
    visited[node][color] = true;
    dp[node][0] = 0; dp[node][1] = 0; dp[node][2] = 0;
    if (b[node] == 1) dp[node][0] = inf;
    if (b[node] == 0) dp[node][1] = inf;
    if (a[node] != b[node]) dp[node][2] = inf;
    if (adj[node].size() == 1) {
        dp[node][0] = b[node] == 0 ? 1 : inf;
        dp[node][1] = b[node] == 1 ? 1 : inf;
        if (color == 2) dp[node][2] = b[node] == a[node] ? 0LL : 1LL;
        else dp[node][2] = b[node] == color ? 0LL : 1LL;
    }
    for (auto u: adj[node]) {
        if (u == parent) continue;
        // if (b[node] == 0) dp[node][0] += min(dp[node][0], 1 + dfs(u, adj, dp, 0, a, b, node));
        // if (b[node] == 1) dp[node][1] = min(dp[node][1], 1 + dfs(u, adj, dp, 1, a, b, node));
        // if (b[node] == color || color == 2) dp[node][2] = min(dp[node][2], dfs(u, adj, dp, 2, a, b, node));
        if (b[node] == 0) dp[node][0] += 1 + dfs(u, adj, dp, 0, a, b, node);
        if (b[node] == 1) dp[node][1] += 1 + dfs(u, adj, dp, 1, a, b, node);
        if (b[node] == color || (color == 2 && a[node] == b[node])) dp[node][2] += dfs(u, adj, dp, 2, a, b, node);
    }
    retval = min(dp[node][0], min(dp[node][1], dp[node][2]));
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] ^= 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        b[i] ^= 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(3, inf)); // dp[i][0] for black, dp[i][1] for white, dp[i][2] for unchanged
    visited.resize(n);
    visited.assign(n, vector <bool> (3, false));
    int ans = dfs(0, adj, dp, 2, a, b, -1);
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) {
        if (test == 1) {
            debug(i, dp[i][0], dp[i][1], dp[i][2]);
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
