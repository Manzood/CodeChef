#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<bool> vis;
set<int> visr;
int dfs(int node, bool l, vector<vector<int>>& left,
        map<int, vector<int>>& right) {
    int retval = 1;
    if (l) {
        if (vis[node]) return 0;
        vis[node] = true;
        for (auto u : left[node]) {
            retval += dfs(u, !l, left, right);
        }
    } else {
        if (visr.count(node)) return 0;
        visr.insert(node);
        for (auto u : right[node]) {
            retval += dfs(u, !l, left, right);
        }
    }
    return retval;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<vector<int>> left(n);
    map<int, vector<int>> right;
    int edges = 0;
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%lld", &k);
        left[i].resize(k);
        edges += k;
        for (auto& x : left[i]) {
            scanf("%lld", &x);
            right[x].push_back(i);
        }
    }
    vis.assign(n, false);
    visr.clear();
    int components = 0;
    int need = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            components++;
            need += dfs(i, true, left, right) - 1;
        }
    }
    int ans = (components - 1 > edges - need) ? -1 : components - 1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
