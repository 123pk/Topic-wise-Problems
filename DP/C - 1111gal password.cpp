/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 242
Approach :- It is standard recrusive problem, where we will use memoisation(dp) to make it more efficient. For each value from '1' to '9' we have three option either we can have
            i-1 ,i or i+1 where i-1>=1 and i+1<=9 
*/
#include<bits/stdc++.h>
using namespace std;

long long dp[1000001][10];
long long mod = 998244353;
 
int main(){
   int n;
   cin>>n;
   
   if(n==1){
       cout<<10;
       exit(0);
   }
   
   memset(dp,-1,sizeof(dp));
   for(int i=1;i<=9;++i){
       dp[0][i] = 1;
   }
   long long ans = 0;
   for(int i = 1;i<n;++i){
       for(int j=1;j<10;++j){
           dp[i][j] = dp[i-1][j]%mod;
           if(j-1>=1)dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
           if((j+1)<=9)dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
           if(i==n-1)ans=(ans+dp[i][j])%mod;
       }
   }
   
    
   cout<<ans<<"\n";
  // cout<<find(n-1,9)<<"\n";
}
