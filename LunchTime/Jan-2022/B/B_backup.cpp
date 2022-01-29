#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s, t;
    cin >> s;
    t = s;
    bool found = false;
    int prev_move = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int diff = s[i] - '0';
        diff = 10 - diff;
        // debug (i, k);
        if (found) {
            if (s[i] < s[i - 1]) {
                int moves = diff;
                k += prev_move; // undoing previous move
                moves += 10 - (s[i - 1] - s[i]);
                if (moves <= k) {
                    t[i] = '0';
                    k -= moves;
                    prev_move = moves;
                } else {
                    break;
                }
            } else {
                t[i] = '0';
                prev_move = 0;
            }
        } else {
            if (diff <= k) {
                t[i] = '0';
                k -= diff;
                found = true;
            } else {
                break;
            }
        }
    }
    // debug (t);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] == '0') {
            ans++;
        } else {
            break;
        }
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
