#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> visited;
map <int, int> ancestors;
vector <int> uniq_children;
int dfs (int node, vector <vector <int>>& adj, vector <int>& a) {
    int retval = 0;
    if (visited[node]) return retval;
    visited[node] = true;
    if (ancestors[a[node]] == 0) retval++;
    for (auto u: adj[node]) {
        retval += dfs (u, adj, a);
    }
    return retval;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        visited.resize (n);
        visited.assign (n, false);
        uniq_children.resize (n);
        uniq_children.assign (n, 0);
        vector <vector <int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%lld%lld", &u, &v);
        }
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
    }
}
