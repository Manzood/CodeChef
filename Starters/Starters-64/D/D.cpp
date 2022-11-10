#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int floorSqrt(int x) {
    if (x == 0 || x == 1) return x;
    int start = 1, end = x / 2, ans;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid > (int)1e9) {
            end = mid - 1;
            continue;
        }
        int sqr = mid * mid;
        if (sqr == x) return mid;
        if (sqr <= x) {
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    vector<vector<int>> values(n);
    vector<vector<int>> moves(n);
    // for (int i = 0; i < n; i++) {
    //     int cur = a[i];
    //     while (cur > 1) {
    //         cur = floorSqrt(cur);
    //         values[i].push_back(cur);
    //     }
    //     reverse(values[i].begin(), values[i].end());
    //     for (int j = 0; j < (int)values[i].size(); j++) {
    //         moves[i].push_back((int)values[i].size() - j);
    //     }
    //     values[i].push_back(a[i]);
    //     moves[i].push_back(0);
    //     cur = a[i];
    //     int cnt = 1;
    //     while (cur > 1 && cur <= (int)1e9) {
    //         cur *= cur;
    //         values[i].push_back(cur);
    //         moves[i].push_back(cnt++);
    //     }
    // }
    // changing how I'm calculating values
    for (int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        set<int> found;
        q.push({a[i], 0});
        found.insert(a[i]);
        while (!q.empty()) {
            pair<int, int> f = q.front();
            // debug(f);
            v.push_back(f);
            q.pop();
            // square and go lower
            if (f.first > 1) {
                int val = floorSqrt(f.first);
                if (!found.count(val)) q.push({val, f.second + 1});
                found.insert(val);
            }
            if (f.first <= (int)1e9) {
                int val = f.first * f.first;
                if (!found.count(val)) q.push({val, f.second + 1});
                found.insert(val);
            }
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < (int)v.size(); j++) {
            values[i].push_back(v[j].first);
            moves[i].push_back(v[j].second);
        }
    }
    // got all values
    vector<vector<int>> dp(n);
    dp[0].resize(values[0].size());
    for (int i = 0; i < (int)moves[0].size(); i++) {
        dp[0][i] = moves[0][i];
        if (i > 0) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
    }
    for (int i = 1; i < n; i++) {
        dp[i].resize(values[i].size());
        int k = 0;
        for (int j = 0; j < (int)values[i].size(); j++) {
            while (k < (int)values[i - 1].size() - 1 &&
                   values[i - 1][k + 1] <= values[i][j]) {
                k++;
            }
            dp[i][j] = dp[i - 1][k] + moves[i][j];
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }
    // debug(dp);
    int ans = (int)1e18 + 7;
    for (int i = 0; i < (int)values[n - 1].size(); i++) {
        ans = min(ans, dp[n - 1][i]);
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
