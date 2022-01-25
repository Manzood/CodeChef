#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int g, p;
        scanf("%lld%lld", &g, &p);
        vector <int> x(10);
        for (int i = 0; i < 10; i++) {
            scanf("%lld", &x[i]);
        }
        int sum = 0;
        for (int i = g; i < 10; i++) {
            sum += x[i];
        }
        int minans = sum / p;
        minans++;
        sum += x[g-1];
        int maxans = sum / p;
        if (sum % p != 0) maxans++;
        printf("%lld %lld\n", minans, maxans);
    }
}

