#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        vector <vector <char>> grid (n, vector <char> (m, '.'));
        vector <vector <int>> dp (n, vector <int> (m, 0)); // up left
        bool win = false;
        int winner = -1;
        for (int i = 0; i < n * m; i++) {
            int x, y;
            scanf("%lld%lld", &x, &y);
            x--; y--;
            char ch;
            if (i % 2 == 0) {
                ch = 'A';
            } else {
                ch = 'B';
            }
            grid[x][y] = ch;

            // recalculates grid;
            if (!win && i >= k * k - 1) {
                for (int tx = 0; tx < n; tx++) {
                    for (int ty = 0; ty < m; ty++) {
                        if (grid[tx][ty] == ch) {
                            if (tx > 0 && ty > 0) {
                                if (grid[tx][ty] == grid[tx-1][ty] && grid[tx][ty] == grid[tx][ty-1] && grid[tx][ty] == grid[tx-1][ty-1]) {
                                    dp[tx][ty] = min (dp[tx-1][ty], min(dp[tx][ty-1], dp[tx-1][ty-1])) + 1;
                                } else {
                                    dp[tx][ty] = 1;
                                }
                            } else {
                                dp[tx][ty] = 1;
                            }
                        } else {
                            dp[tx][ty] = 0;
                        }
                    }
                }
            }

            if (!win && i >= k * k - 1) {
                for (int ti = 0; ti < n; ti++) {
                    for (int j = 0; j < m; j++) {
                        if (dp[ti][j] >= k) {
                            // debug (i);
                            win = true;
                            winner = i % 2;
                            break;
                        }
                    }
                }
            }
        }
        if (winner == -1) {
            printf("Draw\n");
        } else if (winner == 0) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
}
