#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0)

int main()
{
    fastIO;
    int t=1;
    cin>>t;
    while(t--){
        ll x,y,ans=-1;
        cin>>x>>y;
        if((y%x)==0){
            y/=x;
            for(int k=1;k<60;k++){
                ll val=y+k;
                if(val%2)continue;
                int cnt=__builtin_popcountll(val);
                if(cnt==k){
                    int tmp=0;
                    for(int i=1;i<=60;i++){
                        if(val&(1LL<<i))tmp+=i;
                    }
                    tmp+=k-1;
                    ans=tmp;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }

return 0;
}
