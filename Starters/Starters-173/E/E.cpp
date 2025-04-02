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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    bool found = true;
    vector<int> ans;
    if (n > 22) {
        found = false;
        // find one of those subsequences
        int val = a[0] % 2;
        for (int i = 1; i < n; i++) {
            if (a[i] % 2 != val) {
                ans = {0, i};
            }
        }
        if (ans.empty()) {
            for (int x = 3; x <= 22 && ans.empty(); x++) {
                // pick two equal and then one distinct
                val = a[0] % x;
                for (int i = 1; i < n && ans.empty(); i++) {
                    if (a[i] % x != val) {
                        set<int> s;
                        int f1 = -1;
                        for (int j = 0; j < n; j++) {
                            if (s.count(a[j])) {
                                f1 = a[j];
                                break;
                            }
                            s.insert(a[j]);
                        }
                        for (int j = 0; j < n; j++) {
                            if (a[j] != f1) {
                                ans.push_back(j);
                                break;
                            }
                        }
                        int cnt = 0;
                        for (int j = 0; j < n; j++) {
                            if (a[j] == f1) {
                                cnt++;
                                ans.push_back(j);
                            }
                            if (cnt == 2) break;
                        }
                        vector<bool> used(n, false);
                        for (auto c : ans) used[c] = true;
                        while ((int)ans.size() < x) {
                            for (int j = 0; j < n; j++) {
                                if (!used[j]) {
                                    ans.push_back(j);
                                    used[j] = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        set<int> x;
        for (int i = 0; i < m; i++) x.insert(b[i]);
        for (int mask = 1; mask < (1LL << n); mask++) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((1LL << i) & mask) {
                    sum += a[i];
                    cnt++;
                }
            }
            if (sum % cnt != 0 || !x.count(sum / cnt)) {
                found = false;
                for (int i = 0; i < n; i++) {
                    if ((1LL << i) & mask) {
                        ans.push_back(i);
                    }
                }
                break;
            }
        }
    }
    if (found) {
        printf("-1\n");
    } else {
        sort(ans.begin(), ans.end());
        printf("%lld\n", (int)ans.size());
        for (int i = 0; i < (int)ans.size(); i++) {
            printf("%lld ", a[ans[i]]);
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
