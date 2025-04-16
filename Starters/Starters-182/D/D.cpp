#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;

    char prev = ' ';
    int b = 0, g = 0, cur = 0;
    int blen = 0, glen = 0;
    int startind = 0, endind = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == prev) {
            cur++;
        } else {
            if (cur >= k) {
                if (prev == 'B') {
                    b++;
                    blen = cur;
                    endind = i - 1;
                    startind = endind - cur + 1;
                } else {
                    g++;
                    glen = cur;
                    endind = i - 1;
                    startind = endind - cur + 1;
                }
            }
            prev = c;
            cur = 1;
        }
    }
    if (cur >= k) {
        if (prev == 'B') {
            b++;
            blen = cur;
            endind = n - 1;
            startind = endind - cur + 1;
        } else {
            g++;
            glen = cur;
            endind = n - 1;
            startind = endind - cur + 1;
        }
    }

    if (b + g == 0) {
        printf("YES\n");
        return;
    }
    if (b + g == 1) {
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == s[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (i < startind) {
                if (s[i] == 'B') {
                    if (b) {
                        int val = k - 1 - left[i];
                        int val2 = blen - val;
                        if (s[i + 1] == s[i]) {
                            val2 = blen - val + right[i + 1];
                        }
                        if (val2 < k) possible = true;
                    } else {
                        if (s[i + 1] != s[i]) {
                            if (glen - k + 1 + right[i + 1] < k)
                                possible = true;
                        } else {
                            if (glen - k + 1 < k) possible = true;
                        }
                    }
                } else {
                    if (b) {
                        if (s[i + 1] != s[i]) {
                            if (blen - k + 1 + right[i + 1] < k)
                                possible = true;
                        } else {
                            if (blen - k + 1 < k) possible = true;
                        }
                    } else {
                        int val = k - 1 - left[i];
                        int val2 = glen - val;
                        if (s[i + 1] == s[i]) {
                            val2 = glen - val + right[i + 1];
                        }
                        if (val2 < k) possible = true;
                    }
                }
            } else if (i > endind) {
                if (s[i] == 'B') {
                    if (b) {
                        int val = k - 1 - right[i];
                        int val2 = blen - val;
                        if (s[i - 1] == s[i]) {
                            val2 = blen - val + left[i - 1];
                        }
                        if (val2 < k) possible = true;
                    } else {
                        if (s[i - 1] != s[i]) {
                            if (glen - k + 1 + left[i - 1] < k) possible = true;
                        } else {
                            if (glen - k + 1 < k) possible = true;
                        }
                    }
                } else {
                    if (b) {
                        if (s[i - 1] != s[i]) {
                            if (blen - k + 1 + left[i - 1] < k) possible = true;
                        } else {
                            if (blen - k + 1 < k) possible = true;
                        }
                    } else {
                        int val = k - 1 - right[i];
                        int val2 = glen - val;
                        if (s[i - 1] == s[i]) {
                            val2 = glen - val + left[i - 1];
                        }
                        if (val2 < k) possible = true;
                    }
                }
            } else {
                continue;
            }
        }

        if (b && (s[0] != 'B' || s[n - 1] != 'B')) {
            if (blen - k + 1 < k) possible = true;
        }
        if (g && (s[0] != 'G' || s[n - 1] != 'G')) {
            if (glen - k + 1 < k) possible = true;
        }

        printf(possible ? "YES\n" : "NO\n");
    } else {
        if (glen - k + 1 < k && blen - k + 1 < k) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
