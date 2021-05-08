#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 2; i <= 10; i++) {
        if (n % i == 0) ans = i;
    }
    printf("%lld\n", ans);
}
