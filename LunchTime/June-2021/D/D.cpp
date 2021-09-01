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
        vector <pair <int, int>> moves(n * m);
        vector <vector <char>> grid (n, vector <char> (m, '.'));

        for (int i = 0; i < n * m; i++) {
            scanf("%lld%lld", &moves[i].first, &moves[i].second);
            moves[i].first--; moves[i].second--;

            if (i % 2 == 0) grid[moves[i].first][moves[i].second] = 'A';
            else grid[moves[i].first][moves[i].second] = 'B';
        }

        int pos = n * m;
        int LOG = 1;
        while (LOG * 2 <= pos) LOG *= 2;
        // int jump = pos;
        bool draw = true;

        while (LOG > 0) {
            // check if the grid at pos - jump has a winner
            int temp = pos - LOG;
            if (temp < 0) {
                LOG /= 2;
                continue;
            }

            for (int i = pos - 1; i >= temp; i--) {
                grid[moves[i].first][moves[i].second] = '.';
            }

            // check the grid
            vector <vector <int>> dp (n, vector <int> (m, 0));
            bool found = false;

            // debug (pos);
            // debug (LOG);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.') {
                        dp[i][j] = 0;
                    } else {
                        if (i > 0 && j > 0) {
                            if (grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i-1][j-1])
                                dp[i][j] = min (dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                            else
                                dp[i][j] = 1;
                        } else {
                            dp[i][j] = 1;
                        }
                    }
                    if (dp[i][j] >= k) {
                        draw = false;
                        found = true;
                        // debug (i);
                        // debug (j);
                    }
                }
            }
            // for (int i = 0; i < n; i++) {
                // for (int j = 0; j < m; j++) {
                    // printf("%c", grid[i][j]);
                // }
                // printf("\n");
            // }
            // debug (found);

            // if it does, go there
            // otherwise, go back
            if (found) {
                pos = temp;
            }
            else {
                for (int i = temp; i < pos; i++) {
                    if (i % 2 == 0) {
                        grid[moves[i].first][moves[i].second] = 'A';
                    } else {
                        grid[moves[i].first][moves[i].second] = 'B';
                    }
                }
            }
            // debug ("printing again");
            // for (int i = 0; i < n; i++) {
                // for (int j = 0; j < m; j++) {
                    // printf("%c", grid[i][j]);
                // }
                // printf("\n");
            // }
            // debug ("done");

            LOG /= 2;
        }

        // debug (pos);
        if (draw) {
            vector <vector <int>> dp (n, vector <int> (m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.') {
                        dp[i][j] = 0;
                    } else {
                        if (i > 0 && j > 0) {
                            if (grid[i][j] == grid[i-1][j] && grid[i][j] == grid[i][j-1] && grid[i][j] == grid[i-1][j-1])
                                dp[i][j] = min (dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                            else
                                dp[i][j] = 1;
                        } else {
                            dp[i][j] = 1;
                        }
                    }
                    if (dp[i][j] >= k) {
                        draw = false;
                        // debug (i);
                        // debug (j);
                    }
                }
            }
        }

        if (draw) {
            // do a final check at the very end, if not found

            printf("Draw\n");
        } else if (pos % 2 == 1) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
}
