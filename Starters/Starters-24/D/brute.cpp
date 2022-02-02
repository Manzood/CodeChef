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
    if (x == 1 && a == 1 && b == 1) {
        printf("1\n");
        return;
    }
    // find all prime factors of b
    int temp = b;
    vector <int> primes;
    int cnt = 0;
    while (temp % 2 == 0) {
        primes.push_back (2);
        cnt = 1;
        temp /= 2;
    }
    for (int i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            primes.push_back (i);
            temp /= i;
            cnt == 1 ? cnt = 2 : cnt = 1;
        }
    }
    if (temp > 1) primes.push_back(temp);
    int ans = 0;
    if (cnt == 1) {
        ans = b;
        int p = primes[0];
        int sum = 1;
        int t = p;
        while (t <= b) {
            sum += t;
            t *= p;
        }
        if (sum != x || sum != a) {
            ans = -1;
        }
    } else {
        bool found = false;
        for (int i = 2; i < 100000; i++) {
            int sum = 0;
            int prod = 1;
            while (prod < b) {
                prod *= i;
            }
            if (prod > 1 && prod == b) {
                // find sum of all factors??
                sum = i + 1;
                prod = i;
                vector <int> divisors = {1, i};
                for (int j = 2; j * j <= i; j++) {
                    if (i % j == 0) {
                        int val1 = j;
                        int val2 = i / j;
                        if (val1 == val2) {
                            sum += val1;
                            prod *= val1;
                            divisors.push_back(val1);
                        } else {
                            sum += val1;
                            sum += val2;
                            prod *= val1;
                            prod *= val2;
                            divisors.push_back(val1);
                            divisors.push_back(val2);
                        }
                    }
                }
                int sum_of_div = 0;
                for (auto d: divisors) {
                    sum_of_div += prod / d;
                }
                // debug (sum_of_div);
                if (sum == x && prod == b && sum_of_div == a) {
                    found = true;
                    ans = i;
                    break;
                }
            }
        }
        if (found) {
            printf("%lld\n", ans);
        } else {
            printf("-1\n");
        }
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
