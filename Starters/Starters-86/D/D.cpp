#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int dfs(int node, vector<vector<int>>& adj, vector<int>& subtree,
        vector<bool>& vis) {
    if (vis[node]) return 0;
    vis[node] = true;
    subtree[node] = 1;
    for (auto u : adj[node]) {
        subtree[node] += dfs(u, adj, subtree, vis);
    }
    return subtree[node];
}

int centroid(int root, vector<vector<int>>& adj, vector<int>& subtree) {
    int ele = -1;
    int n = (int)adj.size();
    for (auto u : adj[root]) {
        if (subtree[u] > n / 2) ele = u;
    }
    if (ele == -1) return root;
    subtree[root] = n - subtree[ele];
    return centroid(ele, adj, subtree);
}

void dfs2(int node, int s, int par, vector<vector<int>>& adj,
          vector<vector<int>>& elements) {
    elements[s].push_back(node);
    for (auto u : adj[node]) {
        if (u != par) dfs2(u, s, node, adj, elements);
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> subtree(n, 0);
    vector<bool> vis(n, false);
    dfs(0, adj, subtree, vis);
    int root = centroid(0, adj, subtree);
    vector<vector<int>> elements(n);
    for (auto u : adj[root]) dfs2(u, u, root, adj, elements);
    priority_queue<pair<int, int>> heap;
    for (auto u : adj[root]) {
        heap.push({(int)elements[u].size(), u});
    }
    printf("%lld\n", root + 1);
    vector<int> ans;
    ans.push_back(root);
    while (heap.size()) {
        pair<int, int> f = heap.top();
        heap.pop();
        if (heap.size()) {
            pair<int, int> s = heap.top();
            heap.pop();
            ans.push_back(elements[f.second].back());
            ans.push_back(elements[s.second].back());
            elements[s.second].pop_back();
            s.first--;
            if (s.first) heap.push(s);
        } else {
            ans.push_back(elements[f.second].back());
        }
        elements[f.second].pop_back();
        f.first--;
        if (f.first) heap.push(f);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i] + 1);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
