/*
Platform :- CSES
Approach :- So we will start with bottom up dp , where dp[i] stores the minimum no of operations require to get ith value from '0' by adding digits 
            dp[i] = min(dp[i-j] + 1,dp[i])  where 'j' is the digit in 'i'
*/
#include<bits/stdc++.h>
using namespace std;

 
int main(){
    
    memset(dp,-1,sizeof(dp));
    
    int n;
    cin>>n;
    
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i=1;i<=n;++i){
        string s = to_string(i);
        for(auto x:s){
            int j = x-'0';
            if((i-j)>=0){
                if(dp[i] == -1){
                    dp[i] = dp[i-j]+1;
                }
                else{
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
    }
    cout<<dp[n]<<"\n";
}
