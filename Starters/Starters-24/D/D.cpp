#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve() {
    int x, a, b;
    scanf("%lld%lld%lld", &x, &a, &b);
    // find all prime factors of b
    int temp = b;
    vector <int> primes;
    while (temp % 2 == 0) {
        primes.push_back (2);
        temp /= 2;
    }
    for (int i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            primes.push_back (i);
            temp /= i;
        }
    }
    if (temp > 1) primes.push_back(temp);
    assert ((int) primes.size() < 1000);
    map <int, int> mp;
    for (auto p: primes) {
        mp[p]++;
    }
    bool flag = true; // N is not the largest number here
    if (mp.size() > 1) {
        flag = false;
    }
    // now we have all prime factors of b
    int prod = 1;
    int largest = -1;
    int gcd = 0;
    int prev = -1;
    int cnt = 0;
    int cur = 0;
    int curprod = 1;
    for (int i = 0; i < (int) primes.size(); i++) {
        if (prev != primes[i]) {
            if (prev > 0 && gcd == 0) gcd = prev;
            else gcd = __gcd(prev, gcd);
            cnt = 1;
            cur = 1;
            prod *= curprod;
            curprod = 1;
        }
        cur--;
        curprod *= primes[i];
        if (cur == 0) {
            cnt++;
            cur = cnt;
            if (flag) largest = curprod;
        }
        prev = primes[i];
    }
    int ans = 0;
    if (flag) {
        ans = largest;
    } else {
        ans = prod / gcd;
    }
    // find all factors of N, check sum
    int sum = ans + 1;
    for (int i = 2; i * i <= ans && sum <= x; i++) {
        if (ans % i == 0) {
            sum += i;
            sum += ans / i;
        }
    }
    if (x == sum) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
