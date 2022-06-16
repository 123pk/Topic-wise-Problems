/*
Platform :- Codeforces 
Contest :- Codeforces Round 800
Approach :- We will check few things , the last index where non_zero value is present and will store it,
            We will traverse through the array and if at any point of time we have our total_sum of values <= 0 , then we cannot have a valid answer/solution. 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         long long A[n];
         int last = 0;
         for(int i=0;i<n;++i){
             cin>>A[i];
             if(A[i])last = i;
         }
         
         long long tot = 0;
         int f = 0;
         for(int i=0;i<n;++i){
             tot+=A[i];
             if(tot <= 0){
                 if(i<last){
                     f=1;break;
                 }
             }
         }
        
        if(f ||  tot)cout<<"NO\n";
        else cout<<"YES\n";
        
       // cout<<ans<<"\n";
    }
}
