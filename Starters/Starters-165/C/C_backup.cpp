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
    vector<int> left = {0}, right;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            left.push_back(i);
            right.push_back(i - 1);
        }
    }
    right.push_back(n - 1);
    int cnt = (int)left.size();
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        int len = right[i] - left[i] + 1;
        ans += (len * (len + 1)) / 2;
        int cur = s[left[i]];
        if (i > 0) {
            int other = s[right[i - 1]];
            if (cur == other) {
                int otherLen = right[i - 1] - left[i - 1] + 1;
                ans += (otherLen / 2) * len;
            }
        }
        if (i > 1) {
            int other = s[right[i - 1]];
            if (cur == other) {
                int otherLen = right[i - 1] - left[i - 1] + 1;
                if (otherLen % 2 == 0) {
                    int prev = s[right[i - 2]];
                    if (prev == s[left[i - 1]]) {
                        int prevLen = right[i - 2] - left[i - 2] + 1;
                        ans += len * prevLen;
                    }
                }
            }
        }
    }
    if (cnt > 1) {
        int i = cnt - 2;
        int len = right[i] - left[i] + 1;
        int otherLen = right[i + 1] - left[i + 1] + 1;
        if (s[right[i]] == s[left[i + 1]]) {
            ans += len * (otherLen / 2);
        }
        i = 0;
        len = right[i] - left[i] + 1;
        otherLen = right[i + 1] - left[i + 1] + 1;
        if (s[right[i]] == s[left[i + 1]]) {
            ans += len * (otherLen / 2);
        }
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
