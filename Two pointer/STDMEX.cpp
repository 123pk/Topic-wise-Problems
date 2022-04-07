/* 
Platform :- Codechef
Contest ;- Codechef Starters 33
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         set<int>mex;
         for(int i=0;i<=n;++i){
             mex.insert(i);
         }
         
         int mex_val = 0;
         long long A[n];
         for(int i=0;i<n;++i){
             cin>>A[i];
              
         }
         sort(A,A+n);
         for(int i=0;i<n;++i){
             //cin>>A[i];
             auto it = mex.begin();
             if(*it == A[i]){
                 mex.erase(*it);
             }
         }
         mex_val = *(mex.begin());
         
         if(mex_val == 1){
             cout<<"-1\n";
         }
         else if(mex_val == 0)cout<<A[0]-1<<"\n";
         else{
             set<long long>unq;
             for(int i=0;i<n;++i){
                 unq.insert(A[i]);
             }
             
             vector<long long>B;
             for(auto&x:unq)B.push_back(x);
             sort(B.begin(),B.end());
             
            // cout<<mex_val<<"\n";
             int c = 0;
             int ans = 0;
             for(int i=0;i<B.size();){
                 int j = i+1;
                 c = 1;
                 while(j<n && (B[j]-B[j-1] == 1)){
                     c++;
                     j++;
                 }
                 
                 if(c>=(mex_val-1))ans++;
                 i = j;
                 //cout<<i<<" "<<ans<<"\n";
             }
             if(ans)ans--;
             cout<<ans<<"\n";
             
             
         }
         
    }
}
