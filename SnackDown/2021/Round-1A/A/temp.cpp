#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main () {
    // printf("123");
    // cout << "Hello";

    int arr[50];
    for (int i = 0; i < 50; i++) {
        arr[i] = 50 - i;
        printf("%d ", arr[i]);
    }
    printf("\n");
    sort (arr, arr + 50);
    for (int i = 0; i < 50; i++) {
        printf("%d ", arr[i]);
    }
    // arr[51] = -1;

    string s;
    cin >> s;
    sort (s.begin(), s.end());
    reverse (s.begin(), s.end());
    string s1, s2;
    s1 = "Hello ";
    s2 = "World";
    string s3 = s1 + s2;
    s3 += "a";

    vector <int> v1(500);
    v1[0] = 0;
    v1.push_back (12);
    v1.pop_back ();

    v1.resize(250);
    v1.clear();

    sort (v1.begin(), v1.end());

    printf("\n");
}

