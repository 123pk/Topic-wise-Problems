/*
Platform :- Codechef
Contest :- Codeforces Starters 29
Approach :- Perform all the operations given in problem and as directed and update the value , do take care of mod 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
     
     int n,m;
     cin>>n>>m;
     
     vector<long long> initial(n);
     for(int i=0;i<n;++i){
         cin>>initial[i];
     }
     long long mod = 1e9+7;
     int idx;
     long long no;
     for(int i=0;i<m;++i){
         int x,y;
         cin>>x>>y;
         x--;
         for(int j=0;j<y;++j){
             cin>>no>>idx;
             idx--;
             long long z = (no*initial[x])%mod;
            // z = (z*initial[idx])%mod;
             initial[idx]+=z;
             initial[idx]%=mod;
         }
         initial[x] = 0;
     }
     
     for(auto&x:initial)cout<<x<<"\n";
}
