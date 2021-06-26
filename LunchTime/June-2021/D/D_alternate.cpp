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
        vector <vector <char>> grid(n, vector <char> (m, '.'));
        vector <vector <int>> up(n, vector <int> (m, 0));
        vector <vector <int>> down(n, vector <int> (m, 0));
        vector <vector <int>> left(n, vector <int> (m, 0));
        vector <vector <int>> right(n, vector <int> (m, 0));
        bool win = false;
        int winner = -1;
        for (int i = 0; i < n * m; i++) {
            int x, y;
            scanf("%lld%lld", &x, &y);
            x--; y--;
            char c;
            int cur;
            if (i % 2 == 0) {
                c = 'A';
                cur = 0;
            } else {
                c = 'B';
                cur = 1;
            }
            grid[x][y] = c;
            up[x][y] = 1;
            down[x][y] = 1;
            left[x][y] = 1;
            right[x][y] = 1;

            if (x > 0) {
                if (grid[x-1][y] == grid[x][y]) {
                    up[x][y] += up[x-1][y];
                    int pos = x - 1;
                    while (pos >= 0 && grid[pos][y] == grid[x][y]) {
                        down[pos--][y]++;
                    }
                }
            }
            if (y > 0) {
                if (grid[x][y-1] == grid[x][y]) {
                    left[x][y] += left[x][y-1];
                    int pos = y - 1;
                    while (pos >= 0 && grid[x][pos] == grid[x][y]) {
                        right[x][pos--]++;
                    }
                }
            }
            if (x < n - 1) {
                if (grid[x+1][y] == grid[x][y]) {
                    down[x][y] += down[x+1][y];
                    int pos = x + 1;
                    while (pos < n && grid[pos][y] == grid[x][y]) {
                        up[pos++][y]++;
                    }
                }
            }
            if (y < m - 1) {
                if (grid[x][y+1] == grid[x][y]) {
                    right[x][y] += right[x][y+1];
                    int pos = y + 1;
                    while (pos < m && grid[x][pos] == grid[x][y]) {
                        left[x][pos++]++;
                    }
                }
            }


            if (!win) {
                int curk = k;
                int curx = x;
                int cury = y;
                while (up[curx][cury] >= curk && right[curx][cury] >= curk && grid[curx][cury] == grid[x][y]) {
                    if (curk <= 1) {
                        winner = cur;
                        win = true;
                        break;
                    } else {
                        curk--;
                        curx--;
                        cury++;
                    }
                }
                curk = k;
                curx = x;
                cury = y;
                while (up[curx][cury] >= curk && left[curx][cury] >= curk && grid[curx][cury] == grid[x][y]) {
                    if (curk <= 1) {
                        winner = cur;
                        win = true;
                        break;
                    } else {
                        curk--;
                        curx--;
                        cury--;
                    }
                }
                curk = k;
                curx = x;
                cury = y;
                while (down[curx][cury] >= curk && left[curx][cury] >= curk && grid[curx][cury] == grid[x][y]) {
                    if (curk <= 1) {
                        winner = cur;
                        win = true;
                        break;
                    } else {
                        curk--;
                        curx++;
                        cury--;
                    }
                }
                curk = k;
                curx = x;
                cury = y;
                while (down[curx][cury] >= curk && right[curx][cury] >= curk && grid[curx][cury] == grid[x][y]) {
                    if (curk <= 1) {
                        winner = cur;
                        win = true;
                        break;
                    } else {
                        curk--;
                        curx++;
                        cury++;
                    }
                }
            }
            // debug (i + 1);
            // for (int ti = 0; ti < n; ti++) {
                // for (int j = 0; j < m; j++) {
                    // printf("%c", grid[ti][j]);
                // }
                // printf("\n");
            // }
            // debug (winner);
        }
        // for (int ti = 0; ti < n; ti++) {
            // for (int j = 0; j < m; j++) {
                // printf("%lld", right[ti][j]);
            // }
            // printf("\n");
        // }
        if (winner == 0) {
            printf("Alice\n");
        } else if (winner == 1) {
            printf("Bob\n");
        } else {
            printf("Draw\n");
        }
    }
}
