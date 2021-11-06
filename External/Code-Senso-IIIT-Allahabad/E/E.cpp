// Problem Link: https://www.codechef.com/CSNS21B/problems/VKMWED
#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        // case 1: F wins
        // calculate M + 1 choose i
        // can die at most n times, so
        int ans = 0;
        int val = 1;
        for (int i = 0; i <= n; i++) {
            ans += val;
            val *= (m - i + 1);
            val /= (i + 1);
        }
        // Case 2: F loses
        // calculate (K + 1) choose i for all k <= m
        // for loop from 1 to n
        for (int i = 1; i <= n; i++) {
        }
    }
}
