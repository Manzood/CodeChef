#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;
constexpr int INF = MOD;

vector<bool> visited;
void dfs(int node, vector<vector<int>>& adj, int& curtime, vector<int>& tout) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto u : adj[node]) {
        dfs(u, adj, curtime, tout);
    }
    tout[node] = curtime;
    curtime++;
}

bool dfs2(int node, vector<vector<int>>& adj, vector<int>& color, int c) {
    if (visited[node]) return true;
    bool retval = true;
    visited[node] = true;
    color[node] = c;
    for (auto u : adj[node]) {
        if (color[u] != -1 && color[u] != color[node]) retval = false;
        retval &= dfs2(u, adj, color, c);
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    swap(n, m);
    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &edges[i].first, &edges[i].second);
        adj[--edges[i].second].push_back(--edges[i].first);
    }
    // do 2 dfs to get the strongly connected components + how many edges per
    // component + condensed graph
    vector<int> tout(n, INF);
    int curtime = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs(i, adj, curtime, tout);
    vector<pair<int, int>> ftime(n);
    for (int i = 0; i < n; i++) {
        ftime[i] = {tout[i], i};
    }
    sort(ftime.rbegin(), ftime.rend());
    vector<vector<int>> transpose(n);
    for (int i = 0; i < n; i++) {
        for (auto x : adj[i]) {
            transpose[x].push_back(i);
        }
    }
    // do the second dfs in the reverse order
    visited.assign(n, false);
    vector<int> color(n, -1);
    int colors_count = 0;
    vector<bool> mark_color(n, false);
    for (int i = 0; i < n; i++) {
        int cur = ftime[i].second;
        if (!visited[cur]) {
            bool found = dfs2(cur, transpose, color, colors_count++);
            mark_color[colors_count - 1] = found;
        }
    }
    // debug(mark_color);
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (!mark_color[color[i]]) {
            ans *= 2;
            ans %= MOD;
        }
    vector<int> sz(n, 0);
    for (int i = 0; i < n; i++) {
        sz[color[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (mark_color[i]) {
            int val = 1;
            for (int j = 0; j < sz[i]; j++) {
                val *= 2;
                val %= MOD;
            }
            val--;
            if (val < 0) val += MOD;
            ans *= val;
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
