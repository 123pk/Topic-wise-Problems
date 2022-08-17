/*
Platform :- CSES
Problemset :- Dynamic Programming
Approach :- So we will try to find for (n,m) --> [ 1 + (n-1,m) + (1,m) ] , [1+(n-2,m)+(2,m)],
            so we try to cut in verticallly and horizontally and the min cost is our solution.
*/

#include<bits/stdc++.h>
using namespace std;

int dp[501][501];

int find(int h,int w){
     
     if(dp[h][w] != -1)return dp[h][w];
     
     if(h == w)return dp[h][w] = 0;
     
     //we have two option
     int val = INT_MAX;
     for(int i=h-1;i>=1;--i){
         val = min(val,1 + find(i,w)+find((h-i),w));
     }
     
     for(int i=w-1;i>=1;--i){
         val = min(val,1+find(h,i)+find(h,w-i));
     }
     
     return dp[h][w] = val;
}
int main(){
    int n,m;
    cin>>n>>m;
    
    memset(dp,-1,sizeof(dp));
    cout<<find(n,m)<<"\n";
}
