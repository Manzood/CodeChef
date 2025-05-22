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

const int N = (int)2e7 + 5;

void sieve(int n) {
    is_prime.resize(n + 1);
    is_prime.assign(n + 1, true);
    primes_list.clear();
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
        primes_list.push_back(i);
    }
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    if (k < n - 1) {
        printf("-1\n");
        return;
    }
    vector<int> ans;
    ans.push_back(k - (n - 2));
    ans.push_back(2 * (k - (n - 2)));
    // print unused primes
    int cur = 1;
    for (int i = 0; i < n - 2; i++) {
        while ((k - (n - 2)) % primes_list[cur] == 0) cur++;
        ans.push_back(primes_list[cur++]);
    }
    int f = 0;
    for (int i = 0; i < n; i++) {
        printf("%lld ", ans[i]);
        if (i > 0) {
            f += gcd(ans[i], ans[i - 1]);
        }
    }
    printf("\n");
    assert(f == k);
}

int32_t main() {
    int t = 1;
    cin >> t;

    sieve(N);

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
