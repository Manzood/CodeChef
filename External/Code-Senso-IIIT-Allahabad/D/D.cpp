// Problem link: https://www.codechef.com/CSNS21B/problems/DLTNODE
#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <bool> visited;
int tree_loc;
int dfs_gcd (int node, vector <int>& a, vector <vector <int>>& adj, vector <int>& parent, vector <int>& g) {
    visited[node] = true;
    int retval = a[node];

    for (auto u: adj[node]) {
        if (!visited[u]) {
            parent[u] = node;
            retval = __gcd(retval, dfs_gcd (u, a, adj, parent, g));
        }
    }

    g[node] = retval;

    return retval;
}

void dfs_flattening (int node, vector<int> &a, vector<vector<int>> &adj, vector<int> &start, vector<int> &end, vector<int> &flattened) {
    if (visited[node]) return;
    flattened.push_back(a[node]);
    visited[node] = true;
    start[node] = tree_loc++;

    for (auto u : adj[node]) {
        dfs_flattening(u, a, adj, start, end, flattened);
    }

    end[node] = tree_loc++;
    flattened.push_back(a[node]);
}

int32_t main () {
    int t;
    // printf("%lld\n", __gcd(123LL, 0LL));
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <vector <int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%lld%lld", &a, &b);
            a--; b--;
            adj[a].push_back (b);
            adj[b].push_back (a);
        }
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        // find gcd of each subtree, and then find the parent of each node. Parent of root is -1
        // also flatten the tree and find the gcd outside of each subtree, take gcd of both

        visited.resize(n, false);
        visited.assign(n, false);
        vector <int> parent(n, -1);
        vector <int> g(n, 0);
        dfs_gcd(0, a, adj, parent, g);

        // flatten the tree
        tree_loc = 0;           // stores the indices while travelling past the tree
        visited.resize(n, false);
        visited.assign(n, false);
        vector <int> flattened, start(n), end(n);       // stores the flattened tree, while start and end can be used to find the range for each individual subtree
        dfs_flattening(0, a, adj, start, end, flattened); // function that flattens the tree, making it
        vector <int> front_prefix(2 * n, 0);
        vector <int> back_prefix(2 * n, 0);

        front_prefix[0] = flattened[0];
        for (int i = 1; i < 2 * n; i++) {
            front_prefix[i] = flattened[i];
            front_prefix[i] = __gcd(front_prefix[i], front_prefix[i-1]);
        }

        back_prefix[2*n-1] = flattened[2*n-1];
        for (int i = 2*n-2; i >= 0; i--) {
            back_prefix[i] = flattened[i];
            back_prefix[i] = __gcd(back_prefix[i], back_prefix[i+1]);
        }

        // find the best answer
        int ans = 0;

        // for (int i = 0; i < n; i++) {
            // printf("%lld ", a[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < 2 * n; i++) {
            // printf("%lld ", flattened[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < 2 * n; i++) {
            // printf("%lld ", front_prefix[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < 2 * n; i++) {
            // printf("%lld ", back_prefix[i]);
        // }
        // printf("\n");

        for (int i = 0; i < n; i++) {
            int val = 0;
            // delete the node
            for (auto u: adj[i]) {
                if (parent[u] == i) {
                    val += g[u];
                }
            }
            // find the answer for the rest of the subtree
            int ind1 = start[i];
            int ind2 = end[i];
            int v1 = 0;
            // debug (i);
            // debug (ind2)
            if (ind1 > 0) {
                v1 = __gcd (front_prefix[ind1-1], v1);
            }
            if (ind2 < n - 1) {
                v1 = __gcd (back_prefix[ind2+1], v1);
            }
            val += v1;
            ans = max (val, ans);
        }
        printf("%lld\n", ans);
    }
}
