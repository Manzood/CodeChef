#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void findSubsequences(int curr, string &arr, string &subarr,
                      vector<string> &res) {
    if (curr == (int)arr.size()) {
        res.push_back(subarr);
        return;
    }
    subarr.push_back(arr[curr]);
    findSubsequences(curr + 1, arr, subarr, res);
    subarr.pop_back();
    findSubsequences(curr + 1, arr, subarr, res);
}

bool check(string &s, string &t) {
    string temp;
    int ptr = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (ptr < (int)t.size() && s[i] == t[ptr]) {
            ptr++;
            continue;
        }
        temp += s[i];
    }
    int n = (int)temp.size();
    vector<int> occ(26, 0);
    for (auto c : temp) {
        occ[c - 'a']++;
    }
    bool odd = n & 1;
    for (int i = 0; i < 26; i++) {
        if (occ[i] & 1) {
            if (odd) {
                odd = false;
            } else {
                return false;
            }
        }
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    string s;
    cin >> s;
    string t;
    if (!check(s, t)) {
        printf("0\n");
        return;
    }
    string subArr;
    vector<string> res;
    vector<string> ans;
    findSubsequences(0, s, subArr, res);
    for (auto sub : res) {
        if (!check(s, sub)) {
            ans.push_back(sub);
        }
    }
    if ((int)ans.size() == 0) {
        printf("-1\n");
        return;
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", (int)ans[0].size());
    cout << ans[0] << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
