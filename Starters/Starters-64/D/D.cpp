#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int MX_N = 64;

int floorSqrt(int x) {
    if (x == 0 || x == 1) return x;
    int start = 1, end = x / 2, ans;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid > (int)1e9) {
            end = mid - 1;
            continue;
        }
        int sqr = mid * mid;
        if (sqr == x) return mid;
        if (sqr <= x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> d(n, vector<int>(MX_N, 0));
    vector<vector<int>> sq(n, vector<int>(MX_N, 0));
    for (int i = 0; i < n; i++) {
        d[i][0] = a[i];
        int val = a[i];
        for (int j = 1; j < MX_N; j++) {
            val = (int)floorSqrt(val);
            d[i][j] = val;
        }
    }
    for (int i = 0; i < n; i++) {
        sq[i][0] = a[i];
        int val = a[i];
        for (int j = 1; j < MX_N; j++) {
            if (val <= (int)1e9) val *= val;
            sq[i][j] = val;
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(d[i].begin(), d[i].end());
    }
    vector<vector<int>> dec(
        n, vector<int>(MX_N,
                       0));  // dec[i][j] -> minimum number of operations to get
                             // increasing order with d[i][j] up to index i
    vector<vector<int>> inc(
        n, vector<int>(
               MX_N,
               0));  // inc[i][j] -> minimum number of operations to get
                     // increasing order with *exactly* sq[i][j] up to index i
    vector<vector<int>> best(
        n,
        vector<int>(
            MX_N,
            0));  // best[i][j] -> minimum number of operaions to get increasing
                  // order with value *up to* sq[i][j] up to index i
    vector<vector<int>> best2(n, vector<int>(MX_N, 0));
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int prev_ptr = 0;
            int ptr = 0;
            for (int j = 0; j < MX_N; j++) {
                bool smaller = d[i][j] <= a[i - 1];
                if (smaller) {
                    while (prev_ptr < MX_N - 1 &&
                           d[i - 1][prev_ptr + 1] <= d[i][j])
                        prev_ptr++;
                    dec[i][j] = best2[i - 1][prev_ptr] + (MX_N - 1 - j);
                } else {
                    while (ptr < MX_N - 1 && sq[i - 1][ptr + 1] <= d[i][j])
                        ptr++;
                    dec[i][j] = best[i - 1][ptr] + (MX_N - 1 - j);
                }
                best2[i][j] = dec[i][j];
                if (j > 0) best2[i][j] = min(best2[i][j], best2[i][j - 1]);
            }
            // calculate inc
            prev_ptr = 0;
            ptr = 0;
            for (int j = 0; j < MX_N; j++) {
                bool smaller = sq[i][j] <= a[i - 1];
                if (smaller) {
                    while (prev_ptr < MX_N - 1 &&
                           d[i - 1][prev_ptr + 1] <= sq[i][j])
                        prev_ptr++;
                    inc[i][j] = best2[i - 1][prev_ptr] + j;
                } else {
                    while (ptr < MX_N - 1 && sq[i - 1][ptr + 1] <= sq[i][j])
                        ptr++;
                    inc[i][j] = best[i - 1][ptr] + j;
                }
                best[i][j] = inc[i][j];
                if (j > 0) best[i][j] = min(best[i][j], best[i][j - 1]);
            }
        } else {
            for (int j = 0; j < MX_N; j++) {
                dec[i][j] = MX_N - 1 - j;
                inc[i][j] = j;
                best[i][j] = 0;
                best2[i][j] = 0;
            }
        }
    }
    int fin = (int)1e18 + 7;
    for (int i = 0; i < MX_N; i++) {
        fin = min(fin, best2[n - 1][i]);
        fin = min(fin, best[n - 1][i]);
    }
    printf("%lld\n", fin);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
