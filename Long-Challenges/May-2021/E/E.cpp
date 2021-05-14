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

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        vector <int> cnt (m + 1, 0);
        for (int i = 1; i <= n && i <= m; i++) {
            cnt[m % i]++;
        }
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            ans += (cnt[i] * (cnt[i] - 1)) / 2;
        }
        debug(ans);
        for (int i = m + 1; i <= n; i++) {
            ans += i - 1;
        }
        printf("%lld\n", ans);
    }
}
