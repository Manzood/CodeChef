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

const int M = 5e5 + 1;

// precompute across *all* testcases

// do the sieve
int number_of_operations = 0;
void sieve (vector <vector <int>>& fact, int n) {
    // find the number of factors
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            fact[j].push_back (i);
            number_of_operations++;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    vector <vector <int>> fact (M);
    sieve (fact, M);
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        int ans = 0;
        for (int b = 2; b <= n && b <= m; b++) {
            int val = m - (m % b);
            // debug (b);
            // for (int i = 0; i < (int) fact[val].size(); i++) {
                // printf("%lld ", fact[val][i]);
            // }
            // printf("\n");
            auto ind = lower_bound (fact[val].begin(), fact[val].end(), b);
            // debug (ind - fact[val].begin());
            ans += ind - fact[val].begin() + 1;
        }
        for (int i = m + 1; i <= n; i++) {
            ans += i - 1;
        }
        printf("%lld\n", ans);
    }
    debug (number_of_operations);
}
