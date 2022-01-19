#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int ans = (int) 1e18;
string current;
string answer;
void recursive (string& s1, string& s2) {
    if (s1.size() == 0 && s2.size() == 0) {
        int cur = 0;
        int cnt = 0;
        // reverse(current.begin(), current.end());
        for (int i = 0; i < (int) current.size(); i++) {
            if (current[i] == '1') {
                cur += cnt;
            } else {
                cnt++;
            }
        }
        // if (current == "10101010") {
        //     debug ("here");
        //     debug (cur);
        // }
        // reverse(current.begin(), current.end());
        if (cur < ans) {
            ans = cur;
            answer = current;
        }
        // debug (current, ans);
    }
    if (s1.size() > 0) {
        current += s1.back();
        s1.pop_back();
        recursive (s1, s2);
        s1 += current.back();
        current.pop_back();
    }
    if (s2.size() > 0) {
        current += s2.back();
        s2.pop_back();
        recursive (s1, s2);
        s2 += current.back();
        current.pop_back();
    }
}

void solve() {
    int n;
    scanf("%lld", &n);
    string s1, s2;
    cin >> s1 >> s2;
    ans = (int) 1e18;
    current.clear();
    recursive(s1, s2);
    reverse(answer.begin(), answer.end());
    debug (answer);
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
