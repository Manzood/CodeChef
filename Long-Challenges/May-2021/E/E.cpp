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

// do the sieve
void sieve (vector <int>& fact, int n) {
    // find the number of factors
    for (int i = 2; i <= n; i++) {
        if (fact[i] == 1) {
            for (int j = 2 * i; j <= n; j+=i) {
                int val = 0;
                int temp = j;
                while (temp % i == 0) {
                    temp /= i;
                    val++;
                }
                // if (j == 6) {
                    // debug (i);
                    // debug (val);
                // }
                fact[j] *= val + 1;
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
        vector <int> fact (m + 1, 1);
        sieve (fact, m);
        for (int i = 0; i < (int) fact.size(); i++) {
            if (fact[i] > 1) fact[i]--;
        }
        int ans = 0;
        set <int> used;
        for (int b = 2; b <= n; b++) {
            int val = m / b;
            if (!used.count(b) && !used.count(val)) {
                debug (b * val);
                debug (fact[b * val]);
                ans += fact[b * val];
                used.insert (val);
                used.insert (b);
            }
        }
        printf("%lld\n", ans);
    }
}
