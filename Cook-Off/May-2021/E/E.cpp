#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        scanf("%lld%lld", &n, &q);
        vector <int> a(n), p(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
        }
        // find the permutation cycles
        vector <pair <int, int>> info (n);
        vector <vector <int>> cycles;
        vector <bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int ind = cycles.size();
                cycles.resize (cycles.size() + 1);
                // int start = p[i];
                int cur = i;
                while (!visited[cur]) {
                    // debug (cur);
                    visited[cur] = true;
                    // debug ("here");
                    cycles[ind].push_back (cur);
                    info[cur] = {ind, cycles[ind].size() - 1};
                    cur = p[cur] - 1;
                }
            }
        }
        // for (int i = 0; i < (int) cycles.size(); i++) {
            // printf("Cycle %lld: ", i + 1);
            // for (auto x: cycles[i]) {
                // printf("%lld ", x);
            // }
            // printf("\n");
        // }
        int onecnt = 0;
        for (int i = 0; i < q; i++) {
            int op;
            scanf("%lld", &op);
            if (op == 1) {
                onecnt++;
            } else if (op == 2) {
                int x, y;
                scanf("%lld%lld", &x, &y);
                // do a swap
                int cycleindx = info[x].first;
                int cycleposx = info[x].second;
                int cycleindy = info[y].first;
                int cycleposy = info[y].second;
                // get their new indexes
                int xindex = cycles[cycleindx][(cycleposx + onecnt) % cycles[cycleindx].size()];
                int yindex = cycles[cycleindy][(cycleposy + onecnt) % cycles[cycleindy].size()];
                // do the swap a bit carefully, update the indexes wherever required in other data structures as well
            } else {
                int x;
                scanf("%lld", &x);
                // print the element at index x
                // find the index you have to print
                // print it
            }
        }
    }
}
