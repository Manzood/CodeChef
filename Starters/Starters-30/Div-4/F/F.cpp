#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int x1, x2, y1, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    x1--; x2--; y1--; y2--;
    int p = (x1 + y1) & 1;
    int other = 2;
    if (((x2 + y2) & 1) == p) {
        other = 3;
    }
    vector <vector <int>> grid(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == x1 && j == y1) {
                grid[i][j] = 1;
            } else if (i == x2 && j == y2) {
                grid[i][j] = 2;
            } else {
                if (((i + j) & 1) == p) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = other;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lld ", grid[i][j]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
