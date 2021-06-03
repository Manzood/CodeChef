#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int dfs (int node, vector <vector <int>>& adj) {
    int retval = 0;
    for (auto x: adj[node]) {
    }
    return retval;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        vector <vector <int>> adj(n);
        vector <int> parent(n, -1);
        for (int i = 0; i < n - 1; i++) {
            int p;
            scanf("%lld", &p);
            p--;
            parent[i + 1] = p;
            adj[p].push_back (i + 1);
        }
        int ans = 0;
        printf("%lld\n", ans);
    }
}
