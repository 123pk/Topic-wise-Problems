/*
Platform :- CSES
Approach :- We will use bottom up approach , here dp[i] -- > stores the max no of pages we can have with atmost 'i' coins ,
            we will traverse from (x to 1 )coins and  ' if( i >= price[j] ) dp[i] = max(dp[i],dp[i-price[j])+pages[j])
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,x;
    cin>>n>>x;
    
    vector<int>price(n),pages(n);
    
    for(int i=0;i<n;++i){
        cin>>price[i];
    }
    
    for(int i=0;i<n;++i)cin>>pages[i];
    
    vector<int>dp(x+1);
    for(int j = 0;j<n;++j){
        for(int i=x;i>=1;--i){
            if(i-(price[j])>=0){
                dp[i] = max(dp[i],dp[i-price[j]]+pages[j]);
            }
        }
    }
    int ans = 0;
    for(auto&x:dp){
        ans = max(ans,x);
    }

    cout<<ans;
    
}
