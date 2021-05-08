#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9 + 7;

int getpow (int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b % 2 == 0) {
		int t = getpow(a, b / 2);
		return (t * t) % mod;
	}
	else {
		int t = getpow(a, (b - 1) / 2);
		return (((a * t) % mod) * t) % mod;
	}
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int ans = 1;
        scanf("%lld", &n);
        // count the number of even numbers until 2 ^ n - 1
        ans = getpow (2, n - 1);
        printf("%lld\n", ans);
    }
}
