#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    vector<int> p(n, -1);
    int ptr = 0;
    int a_cnt = 0, b_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a_cnt++;
        } else {
            b_cnt++;
            if (a_cnt > b_cnt) {
                while (a_cnt > b_cnt) {
                    if (s[ptr] == 'A')
                        a_cnt--;
                    else
                        b_cnt--;
                    ptr++;
                }
                while (ptr < n && s[ptr] != 'A') ptr++;
            } else {
                while (b_cnt > a_cnt) {
                    debug(ptr);
                    ptr--;
                    if (s[ptr] == 'A')
                        a_cnt++;
                    else if (s[ptr] == 'B')
                        b_cnt++;
                }
            }
            p[i] = ptr;
        }
    }
    ptr = 0, a_cnt = 0, b_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            b_cnt++;
        } else {
            a_cnt++;
            if (b_cnt > a_cnt) {
                while (b_cnt > a_cnt) {
                    if (s[ptr] == 'B')
                        b_cnt--;
                    else
                        a_cnt--;
                    ptr++;
                }
                while (ptr < n && s[ptr] != 'B') ptr++;
            } else {
                while (a_cnt > b_cnt) {
                    debug(i, a_cnt, b_cnt);
                    ptr--;
                    if (s[ptr] == 'B')
                        b_cnt++;
                    else
                        a_cnt++;
                }
            }
            p[i] = ptr;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = (i - p[i]) * (n - i);
        ans += val;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
