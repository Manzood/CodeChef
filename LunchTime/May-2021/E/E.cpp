#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int ans;

int dfs (int node, vector <vector <int>>& adj, string& s) {
    // returns depth of the deepest token
    int depth = 0;
    for (auto u: adj[node]) {
        depth = max (depth, dfs (u, adj, s));
    }
    if (s[node] == '1') {
        depth++;
    } else {
        ans += depth;
    }
    return depth;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        vector <vector <int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int p;
            scanf("%lld", &p);
            adj[--p].push_back (i + 1);
        }
        dfs (0, adj, s);
        printf("%lld\n", ans);
    }
}
