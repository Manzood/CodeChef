#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int d1, v1, d2, v2, p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    // simulate it 
    int cur = 0;
    int d = 1;
    while (cur < p) {
        if (d >= d1) cur += v1;
        if (d >= d2) cur += v2;
        d++;
    }
    printf("%d\n", --d);
}