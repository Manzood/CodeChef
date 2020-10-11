#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int MX = (int) 5e6;

int main() {
    int n; scanf("%d", &n);
    vector <bool> isprime(MX, true);
    isprime[0] = false; isprime[1] = false;
    for (int i = 2; i*i < MX; i++) {
        if (isprime[i]) {
            for (int j = 2*i; j < MX; j+=i) {
                isprime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 0; count < n; i++) {
        if (isprime[i]) {
            count++;
            printf("%d\n", i);
        }
    }
}