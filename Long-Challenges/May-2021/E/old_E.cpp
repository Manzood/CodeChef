#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<string> vec_splitter(string s) {
    s += ','; vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out( vector<string> __attribute__ ((unused)) args, __attribute__ ((unused)) int idx, __attribute__ ((unused)) int LINE_NUM) { cerr << endl; } template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef local
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif

// vector <int> dp;

vector <bool> is_prime;
void altered_sieve (vector <int>& dp, int n) {
    for (int i = 2; i <= n; i++) {
        if (dp[i] == 1) {
            int cur = 2 * i;
            while (cur <= n) {
                is_prime[cur] = false;
                int temp = cur;
                int cnt = 0;
                // could calculate temp in O(1)
                while (temp > 1 && temp % i == 0) {
                    temp /= i;
                    cnt++;
                }
                // if (cnt == 0) cnt++;
                dp[cur] *= cnt + 1;
                // debug (cur);
                // debug (cnt);
                cur += i;
            }
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        // int cnt = 0;
        is_prime.resize (n + 1);
        vector <int> cnt (m + 1, 0);
        is_prime.assign (n + 1, true);
        vector <int> dp(n + 1, 1);
        altered_sieve (dp, n);
        int ans = 0;
        vector <int> prime_count (max(m + 1, n + 1), 0);
        for (int i = 1; i <= n && i <= m; i++) {
            if (is_prime[i]) cnt[m % i]++;
            if (is_prime[i] && m % i == 0 && i > 1) cnt[i]++;
            if (is_prime[i]) prime_count[i]++;
            // if (is_prime[i]) debug (i, m % i, cnt[m % i]);
        }
        for (int i = 1; i <= m; i++) {
            debug (cnt[i]);
            ans += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        for (int i = 2; i <= n; i++) {
            ans += max (dp[i] - 1, 1LL);
            // debug(i);
            // debug(dp[i]);
        }
        vector <int> factors;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i] && m % i == 0) {
                factors.push_back(i);
            }
        }
        // debug(ans);
        for (int i = 0; i < (int) factors.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (factors[i] % factors[j] != 0 && factors[j] % factors[i] != 0) ans++;
            }
            // int val = max (n, m) - i - 1;
            // int num_primes = prime_count[max(n, m)] - prime_count[i];
            // debug (factors[i], val);
            // ans += val - num_primes;
        }
        // count all pairs larger than m
        for (int i = m + 1; i <= n; i++) {
            // debug (i, i - dp[i], i - 2, ans);
            // debug(is_prime[8]);
            // debug(is_prime[6]);
            // debug (is_prime[5]);
            if (!is_prime[i]) ans += i - dp[i];
            else ans += i - 2;
        }
        printf("%lld\n", ans);
    }
}
