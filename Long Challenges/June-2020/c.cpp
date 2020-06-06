#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		scanf("%d",&n);
		vector <int> a(n);
		int five=0,ten=0,fifteen=0;
		bool possible=true;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			if (a[i]==5) 
				five++;
			else if (a[i]==10) {
				ten++;
				if (five==0) {
					possible=false;
				}
				else 
					five--;
			}
			else {
				fifteen++;
				if (ten==0 && five<2) {
					possible=false;
				}
				else {
					if (ten)
						ten--;
					else {
						five-=2;
					}
				}
			}
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
