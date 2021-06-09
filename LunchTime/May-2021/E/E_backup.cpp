#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

// find the deepest node from the current node and then swap it, adding distance to answer
int ans = 0;

pair <int, int> dfs2 (int node, vector <vector <int>>& adj, string s, int dist) {
    pair <int, int> retval = {-1, -1};
    if (s[node] == '1') retval = {node, dist};
    for (auto x: adj[node]) {
        auto temp = dfs2 (x, adj, s, dist + 1);
        if (temp.second > retval.second) {
            retval = temp;
        }
    }
    return retval;
}

void dfs (int node, vector <vector <int>>& adj, string& s) {
    pair <int, int> retval = {-1, -1}; // index, distance
    if (s[node] == '0') {
        retval = dfs2 (node, adj, s, 0);
        // if (node == 0) {
            // printf("%lld %lld\n", retval.first + 1, retval.second);
        // }
        if (retval.second != -1) ans += retval.second;
        if (retval.first != -1) swap (s[node], s[retval.first]);
    }
    for (auto x: adj[node]) {
        dfs (x, adj, s);
    }
    // return the index of the token at the largest distance from here
    // return retval;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
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
        dfs (0, adj, s);
        printf("%lld\n", ans);
    }
}
