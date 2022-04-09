/*
Platform :- CSES
Approach :- Since we want ordered combination so it is good to have the smaller denomination coins to be use before other largers ones ,
            for dp[i][j] state stores the no of ways to have the value of 'j' from 'i'th valued coin 
*/
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    
    int A[n];
    for(int i=0;i<n;++i)cin>>A[i];
    
    vector<int>dp(x+1);
    dp[0] = 1;
    int mod = 1e9+7;
    
    for(int i=0;i<n;++i){
        for(int j=1;j<=x;++j){
            if((j-A[i])>=0){
                dp[j]+=dp[j-A[i]];
                dp[j]%=mod;
            }
        }
    }
    cout<<dp[x];
}
