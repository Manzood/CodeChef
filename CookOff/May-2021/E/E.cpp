#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        scanf("%lld", &n);
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
                    cycles[ind].push_back (a[cur]);
                    info[cur] = {ind, cycles[ind].size() - 1};
                    cur = p[cur] - 1;
                }
            }
        }
        int onecnt = 0;
        for (int i = 0; i < (int) cycles.size(); i++) {
            reverse (cycles[i].begin(), cycles[i].end());
        }
        for (int i = 0; i < n; i++) {
            info[i].second = (int) cycles[info[i].first].size() - 1 - info[i].second;
        }
        // for (int i = 0; i < (int) cycles.size(); i++) {
            // printf("Cycle %lld: ", i + 1);
            // for (int j = (int) cycles[i].size() - 1; j >= 0; j--) {
                // printf("%lld ", cycles[i][(j + onecnt) % cycles[i].size()]);
            // }
            // printf("\n");
        // }
        scanf("%lld", &q);
        for (int i = 0; i < q; i++) {
            int op;
            scanf("%lld", &op);
            if (op == 1) {
                onecnt++;
                // for (int k = 0; k < (int) cycles.size(); k++) {
                    // printf("Cycle %lld: ", k + 1);
                    // for (int j = (int) cycles[k].size() - 1; j >= 0; j--) {
                        // printf("%lld ", cycles[k][(j + onecnt) % cycles[k].size()]);
                    // }
                    // printf("\n");
                // }
            } else if (op == 2) {
                int x, y;
                scanf("%lld%lld", &x, &y);
                x--; y--;
                swap (cycles[info[x].first][(info[x].second + onecnt) % cycles[info[x].first].size()], cycles[info[y].first][(info[y].second + onecnt) % cycles[info[y].first].size()]);
                // for (int k = 0; k < (int) cycles.size(); k++) {
                    // printf("Cycle %lld: ", k + 1);
                    // for (int j = (int) cycles[k].size() - 1; j >= 0; j--) {
                        // printf("%lld ", cycles[k][(j + onecnt) % cycles[k].size()]);
                    // }
                    // printf("\n");
                // }
            } else {
                int x;
                scanf("%lld", &x);
                // print the element at index x
                x--;
                // debug (info[x].second);
                printf("%lld\n", cycles[info[x].first][(info[x].second + onecnt) % cycles[info[x].first].size()]);
            }
        }
    }
}
