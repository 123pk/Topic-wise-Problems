/*
Platform :- Atocder
Contest :- Educational DP Contest
Approach :- We will use recursion and memoisation in bottom up manner , so we will start from (n,m) last cell and will do 'up' and 'left' operation which is equivalent 
            to 'right' and 'down' in top down approach . So we will check if current cell is already blocked then no of ways to reach there is 0(dp[i][j] = 0)
            else dp[i][j] = no_of_ways_to_reach(i-1,j) + no_of_ways_to_reach(i,j-1) --- ( left and up movement) . If we area at starting cell if it is not blocked we 
            set dp[i][j] = 1
            
            -- for tabular form dp[i][j] = dp[i-1][j] + dp[i][j-1] for bottom up
*/
#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int mod = 1e9+7;

int find(int i,int j,vector<vector<char>>&A){
    
    if(i<0 || j<0)return 0;
    
    if(dp[i][j] != -1)return dp[i][j];
    
    if(A[i][j] == '#')return dp[i][j] = 0;
    if(i == 0&&j == 0){
        return dp[i][j] = 1;
    }
    int val = find(i-1,j,A)%mod  +find(i,j-1,A)%mod;
    
    return dp[i][j] = val%mod;
}

int main(){
     int h,w;
     cin>>h>>w;
     
     vector<vector<char>> ch(h,vector<char>(w));
     for(int i=0;i<h;++i){
         for(int j=0;j<w;++j){
             cin>>ch[i][j];
         }
     }
     memset(dp,-1,sizeof(dp));
     cout<<find(h-1,w-1,ch);
     
     
}
