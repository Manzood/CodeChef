//Can be used to test solutions of multiple problems
#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

int main(int argc, char *argv[])
{
	srand(atoi(argv[1]));
    printf("1\n");
	int n=rand(2,15);
    int m = rand (1, 15);
	printf("%d %d\n",n, m);
}
