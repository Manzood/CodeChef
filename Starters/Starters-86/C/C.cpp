#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> primes_list;
vector<bool> is_prime;

const int N = (int)1e6 + 5;

vector<int> tno(N, -1);

void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    primes_list.clear();
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) is_prime[j] = false;
        primes_list.push_back(i);
    }
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<int> a(n);
    int gcd = 1;
    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if ((int)s.size() < 2) s.insert(a[i]);
        if (i == 0)
            gcd = a[i];
        else
            gcd = __gcd(a[i], gcd);
    }
    if ((int)s.size() < 2) {
        printf("0\n");
        return;
    }
    if (gcd > 1) {
        printf("1\n%lld\n", gcd);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (auto x : primes_list) {
            if (x * x > a[i]) break;
            if (a[i] % x == 0) tno[x] = test;
            while (a[i] % x == 0) a[i] /= x;
        }
        if (a[i] > 1) tno[a[i]] = test;
    }
    int ans = m + 1;
    for (auto i : primes_list) {
        if (i > m) break;
        if (tno[i] != test) {
            ans = i;
            break;
        }
    }
    if (ans <= m)
        printf("1\n%lld\n", ans);
    else
        printf("2\n2 3\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    sieve(N);
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
