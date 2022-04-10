/*
Platform :- CSES
Approach :- TOP DOWN DP 
*/
#include<bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    
     
    
    int n;
    cin>>n;
    
    char ch[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>ch[i][j];
        }
    }
    int mod = 1e9+7;
    //what is the values
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==0||j==0){
                if(i==0 && j ==0){
                    if(ch[i][j] == '*')dp[i][j] = 0;
                    else dp[i][j] = 1;
                }
                else if(i==0){
                    if(ch[i][j] =='*')dp[i][j] = 0;
                    else dp[i][j]+=dp[i][j-1];
                }
                else{
                    if(ch[i][j] =='*')dp[i][j] = 0;
                    else dp[i][j]+=dp[i-1][j];
                    
                }
            }
            else{
                if(ch[i][j] == '*')dp[i][j] = 0;
                else dp[i][j] = dp[i][j-1]+dp[i-1][j];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n-1][n-1];
}
