/*
Platform :- CSES
Problem set :- Dynamic Programming
Approach :- We will finnd the max difference between score of player1 and player2 using DP ( recursion + memoisation)
           --> let x = score1 - score2
           ---> Let tot_sum  = score1+score2 
           --> simplifying we will get (tot_sum + x) = 2*score1 , so score of (player1 = (tot_sum + x)/2 )
           
           We try all possible options.
           
Time Complexity :- O(n^2)
Space Compleity :- O(n^2)                         
*/
#include<bits/stdc++.h>
using namespace std;
 
long long dp[5001][5001];
 
long long find(int i,int j,vector<long long>&A){
    
    if(i>j)return 0;
    
    if(dp[i][j] )return dp[i][j];
    
    long long val = 0;
     
        val = max(A[i]-find(i+1,j,A),A[j]-find(i,j-1,A));
        
        return dp[i][j] = val;
     
}
 
int main(){
    int n;
    cin>>n;
    
    vector<long long>A(n);
    long long tot = 0;
    for(int i=0;i<n;++i){
        cin>>A[i];
        tot+=A[i];
    }
    
    memset(dp,0,sizeof(dp));
    
    long long ans = tot+find(0,n-1,A);
    ans>>=1ll;
    cout<<ans<<"\n";
}
