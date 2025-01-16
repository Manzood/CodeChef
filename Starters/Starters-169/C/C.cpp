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
    vector<int> occ(26);
    for (int i = 0; i < n; i++) {
        occ[s[i] - 'a']++;
    }
    int cnt = 0, oddCnt = 0;
    for (int i = 0; i < 26; i++) {
        if (occ[i] > 0) cnt++;
        if (occ[i] & 1) oddCnt++;
    }
    if (cnt == 1) {
        printf("-1\n");
        return;
    } else if (oddCnt > 1) {
        printf("0\n");
        return;
    }
    vector<vector<int>> suff(n, vector<int>(26, -1)),
        freq(n, vector<int>(26, 0));
    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            for (int j = 0; j < 26; j++) {
                suff[i][j] = suff[i + 1][j];
                freq[i][j] = freq[i + 1][j];
            }
        }
        suff[i][s[i] - 'a'] = i;
        freq[i][s[i] - 'a']++;
    }
    string ans;
    int cur = 0, odd = oddCnt;
    while (cur < n) {
        for (int i = 0; i < 26; i++) {
            int ind = suff[cur][i];
            if (ind == -1) continue;
            int curOdd = odd;
            if (occ[i] & 1)
                curOdd--;
            else
                curOdd++;
            bool okay = false;
            if (curOdd == 2) {
                ans += (char)i + 'a';
                cur = n;
                break;
            }
            if (curOdd == 1) {
                if (ind == n - 1) continue;
                for (int j = 0; j < 26; j++) {
                    if (j == i) continue;
                    if (freq[ind + 1][j] > 0) {
                        ans += (char)i + 'a';
                        occ[i]--;
                        cur = ind + 1;
                        okay = true;
                        break;
                    }
                }
            } else {
                if (ind == n - 1) continue;
                int rem = 0;
                for (int j = 0; j < 26; j++) {
                    if (freq[ind + 1][j] > 0) rem++;
                }
                if (rem >= 2) {
                    ans += (char)i + 'a';
                    occ[i]--;
                    cur = ind + 1;
                    okay = true;
                }
            }
            if (okay) {
                odd = curOdd;
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
