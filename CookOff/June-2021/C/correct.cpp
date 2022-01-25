//Author- Akshit Monga
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

void print(int a,int b,int c){
    cout<<a<<" "<<b<<" "<<c<<'\n';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    assert(1<=t and t<=1e3);
    int sig_n=0;
    while(t--){
        int n; cin>>n;
        assert(1<=n and n<=1e4);
        int arr[n];
        for(int i=0;i<n;i++){cin>>arr[i]; assert(0<=arr[i] and arr[i]<(1<<30));}

        sig_n+=n;
        assert(1<=sig_n and sig_n<=2*(1e4));

        if(n==1){
            // cout<<0<<'\n';
            continue;
        }

        if(n==2){
            if(arr[0]==arr[1]) cout<<-1<<'\n';
            // else cout<<0<<'\n';
            continue;
        }


        if(n==3){

            // all elements equal
            if(arr[0]==arr[1] and arr[1]==arr[2]){

                // all equal to 0
                if(arr[0]==0) cout<<-1<<'\n';

                // all equal to some non 0 value
                else{
                    // cout<<1<<'\n';
                    // print(1,3,2);
                }
                continue;
            }

            // if first and last equal
            if(arr[0]==arr[2]){
                // cout<<0<<'\n';
                continue;
            }

            // if middle is 0
            if(arr[1]==0){
                // cout<<1<<'\n';
                // if(arr[0]) print(1,2,3);
                // else print(3,2,1);
                continue;
            }

            // else -1
            cout<<-1<<'\n';
            continue;
        }

        // now n>=4

        set<int> vals;
        for(auto i:arr) vals.insert(i);

        // all elements equal
        if((int)vals.size()==1){
            // all equal to 0
            if(arr[0]==0) cout<<-1<<'\n';

            // all equal to some non 0 value
            else{
                vector<array<int,3>> ops;
                int i=1,j=3;
                for(int k=2;k<=n;k+=2) ops.push_back({i,j,k});
                cout<<(int) ops.size()<<'\n';
                for(auto triplet:ops) print(triplet[0],triplet[1],triplet[2]);
            }
            continue;
        }

        map<int,int> evens;
        map<int,int> odds;
        for(int i=0;i<n;i++){
            if(i%2) evens[arr[i]]=i+1;
            else odds[arr[i]]=i+1;
        }

        vector<array<int,3>> ops;

        if((int)evens.size()>=2){
            auto ptr=evens.begin();
            int i=ptr->second;
            ptr++;
            int j=ptr->second;
            for(int k=1;k<=n;k+=2) ops.push_back({i,j,k});
            i=1;j=3;
            for(int k=2;k<=n;k+=2) ops.push_back({i,j,k});
        }
        else if((int) odds.size()>=2){
            auto ptr=odds.begin();
            int i=ptr->second;
            ptr++;
            int j=ptr->second;
            for(int k=2;k<=n;k+=2) ops.push_back({i,j,k});
            i=2;j=4;
            for(int k=1;k<=n;k+=2) ops.push_back({i,j,k});
        }

        // if both the conditions are not run array is already good.
        // cout<<(int) ops.size()<<'\n';
        // for(auto triplet:ops) print(triplet[0],triplet[1],triplet[2]);

    }
    return 0;
}
