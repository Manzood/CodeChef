#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

vector <int> get_primes (vector <bool>& primes) {
    int n = 500;
    vector <int> storage;
    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= n; i += p)
                primes[i] = false;
        }
    }
    for (int i = 3; i <= n; i++) {
        if (primes[i] == true) {
            storage.push_back (i);
        }
    }
    return storage;
}

int32_t main () {
    int t;
    vector <bool> is_prime(501, true);
    vector <int> primes;
    primes = get_primes(is_prime);
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        if (n % 2 == 0) {
            printf("%lld %lld\n", 2 * n, n);
        } else if (n % 3 != 0){
            // n is not divisible by 2 and 3
            printf("%lld %lld\n", n * 3, n * 2);
        } else {
            // since each prime number > 2 is odd, prime + 1 is divisble by 2
            // find the first prime number that doesn't divide n
            // answer is prime, prime + 1
            for (auto p: primes) {
                if (p > 2 && n % p != 0) {
                    // n is not divisible by p
                    printf("%lld %lld\n", n * (p + 1), n * (p));
                    break;
                }
            }
        }
    }
}
