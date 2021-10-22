#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == 7 || b == 7 || c == 7) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
