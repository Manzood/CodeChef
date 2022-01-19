#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

#define int long long
using namespace std;

pair <int, int> check (string& s) {
    // returns number of 1s, number of zeroes till first 1
    pair <int, int> retval = {0, 0};
    int n = s.size();
    int cnt = 0;
    int ones = 0;
    bool found = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            if (!found) {
                retval.second = cnt;
            }
            ones++;
            found = true;
        } else {
            cnt++;
        }
    }
    retval.first = ones;
    return retval;
}

int check2 (string& s) {
    int retval = 0;
    int n = s.size();
    bool found = false;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            retval++;
            found = true;
        } else {
            if (found) {
                return retval;
            }
        }
    }
    return retval;
}

void solve() {
    int n;
    scanf("%lld", &n);
    string s1, s2;
    cin >> s1 >> s2;
    vector <int> ans;
    // remember to reverse
    int cnt = 0;
    int tot[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0') {
            tot[0]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s2[i] == '0') {
            tot[1]++;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        if ((int) s1.size() == 0 || (int) s2.size() == 0) {
            break;
        }
        a = s1.back() - '0';
        b = s2.back() - '0';
        if (a == 1 && b == 1) {
            s1.pop_back ();
            ans.push_back (1);
        } else if (a + b == 1) {
            if (a == 1) {
                s1.pop_back();
            } else {
                s2.pop_back();
            }
            ans.push_back (1);
        } else {
            // choose which one to pop
            pair <int, int> val1 = check(s1), val2 = check(s2);
            int ones1 = val1.first;
            int ones2 = val2.first;
            int zeroes1 = val1.second;
            int zeroes2 = val2.second;
            // zeroes1 += chosen[0];
            // zeroes1 += chosen[1];
            // debug (ones1,ones2);
            // debug (ans.size());
            // debug (zeroes1, zeroes2);
            if ((ones2 > 0 && ones2 * zeroes1 > ones1 * zeroes2) || ones1 == 0)  {
                s2.pop_back();
                tot[1]--;
                // debug ("chose s2");
            } else {
                if (ones2 > 0 && ones1 > 0 && ones2 * zeroes1 == ones1 * zeroes2) {
                    // old ties logic
                        // if (zeroes1 < zeroes2) {
                        //     s1.pop_back();
                        //     tot[0]--;
                        // } else {
                        //     if (zeroes1 == zeroes2) {
                        //         // debug (tot[0], tot[1]);
                        //         if (tot[0] < tot[1]) {
                        //             s1.pop_back();
                        //             tot[0]--;
                        //         } else {
                        //             s2.pop_back();
                        //             tot[1]--;
                        //         }
                        //     } else {
                        //         s2.pop_back();
                        //         tot[1]--;
                        //     }
                        // }
                    // new ties logic
                    if (check2(s1) > check2(s2)) {
                        s1.pop_back();
                    } else {
                        s2.pop_back();
                    }
                } else {
                    s1.pop_back();
                    tot[0]--;
                }
                // debug ("chose s1");
            }
            ans.push_back (0);
            cnt++;
        }
    }
    if ((int) ans.size() != 2 * n) {
        while ((int) s1.size() > 0) {
            int a = s1.back() - '0';
            ans.push_back (a);
            s1.pop_back();
        }
        while ((int) s2.size() > 0) {
            int a = s2.back() - '0';
            ans.push_back (a);
            s2.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    int p = 0;
    cnt = 0;
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (ans[i] == 0) {
            cnt++;
        } else {
            p += cnt;
        }
    }
    debug (ans);
    printf("%lld\n", p);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}

