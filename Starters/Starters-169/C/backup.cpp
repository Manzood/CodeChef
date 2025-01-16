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
    vector<int> occ(26, 0);
    for (auto c : s) {
        occ[c - 'a']++;
    }
    int oddCnt = 0;
    int tot = 0;
    for (auto x : occ) {
        if (x & 1) {
            oddCnt++;
        }
        if (x > 0) {
            tot++;
        }
    }
    if (oddCnt > 1) {
        printf("0\n");
        return;
    }
    if (tot == 1) {
        printf("-1\n");
        return;
    }
    string ans;
    if (oddCnt == 1) {
        bool found = false;
        char oddChar = 'a';
        for (int i = 0; i < 26; i++) {
            if (occ[i] > 0 && !(occ[i] & 1)) {
                if (found) {
                    int rightmost = 0;
                    for (int j = 0; j < n; j++) {
                        if (s[j] == i + 'a') {
                            rightmost = j;
                        }
                    }
                    int cnt = 0;
                    for (int j = 0; j < rightmost; j++) {
                        if (s[j] == oddChar) {
                            cnt++;
                        }
                    }
                    if (cnt >= 2) {
                        for (int j = 0; j < cnt / 2; j++) {
                            ans += oddChar;
                            ans += oddChar;
                        }
                        ans += (char)i + 'a';
                    } else if (cnt > 0 && occ[oddChar - 'a'] > 2) {
                        for (int j = 0; j < cnt; j++) ans += oddChar;
                        ans += (char)i + 'a';
                        ans += oddChar;
                    } else {
                        ans += (char)i + 'a';
                    }
                }
                break;
            } else if (occ[i] > 0) {
                oddChar = (char)i + 'a';
                found = true;
            }
        }
    } else {
        int i;
        for (i = 0; i < 26; i++) {
            if (occ[i] > 0) {
                ans += (char)i + 'a';
                break;
            }
        }
        for (int j = i + 1; j < 26; j++) {
            if (occ[j] > 0) {
                bool found = false, after = false;
                int otherInd = -1;
                for (int x = 0; x < n; x++) {
                    if (s[x] == i + 'a') {
                        found = true;
                    } else if (found && s[x] == j + 'a') {
                        after = true;
                        otherInd = i;
                    }
                }
                if (after) {
                    found = false;
                    int cnt = 0;
                    for (int x = 0; x < otherInd; x++) {
                        if (s[x] == i + 'a') {
                            found = true;
                            cnt++;
                        }
                    }
                    ans = "";
                    ans += (char)i + 'a';
                    for (int x = 1; x + 2 <= cnt; x += 2) {
                        ans += (char)i + 'a';
                        ans += (char)i + 'a';
                    }
                    ans += (char)j + 'a';
                } else {
                    ans += (char)j + 'a';
                    reverse(ans.begin(), ans.end());
                }
                break;
            }
        }
    }
    printf("%lld\n", (int)ans.size());
    cout << ans << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
