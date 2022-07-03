// Todo: make a better generator, eventually
#include "bits/stdc++.h"
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

// generate vector of a particular size with values between start and end,
// inclusive
vector<int> generate_vector(int start, int end, int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) {
        int x = rand(start, end);
        temp[i] = x;
    }
    return temp;
}

// generate a permuation of a particular size
vector<int> generate_permutation(int size) {
    vector<int> temp(size);
    for (int i = 0; i < size; i++) temp[i] = i + 1;
    random_shuffle(temp.begin(), temp.end());
    return temp;
}

// print a vector, in its entirety
void print_vector(vector<int>& v) {
    for (auto x : v) printf("%d ", x);
    printf("\n");
}

int main([[maybe_unused]] int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // test cases
    printf("1\n");
    int n = rand(2, 100);
    printf("%d", n);
    // int m = rand (2, 10);
    // printf(" %d", m);
    printf("\n");
    int x = rand(1, n);
    // printf("%d\n", x);
    for (int i = 1; i <= n; i++) {
        if (i == x) {
            int right = rand(1, 2);
            if ((right == 1 && x > 1) || x == n) {
                int l = rand(1, x - 1);
                int r = rand(l, x - 1);
                printf("%d %d\n", l, r);
            } else {
                int l = rand(x + 1, n);
                int r = rand(l, n);
                printf("%d %d\n", l, r);
            }
        } else {
            int l = rand(1, x);
            int r = rand(x, n);
            printf("%d %d\n", l, r);
        }
    }
    puts("");
}
