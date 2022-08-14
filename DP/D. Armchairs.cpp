/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 109
Approach :- We have option to assign ith person chair occupied to jth chair tha is not occupied,
             we maintain two array one store the index of occupied chairs and one store the unoccupied chairs.
*/
#include<bits/stdc++.h>
using namespace std;

long long dp[5001][5001];

long long find(int i,int j,vector<int>&A,vector<int>&B){
    
    if(i>=A.size())return 0;
    if(j>=B.size())return 1e18;
    
    if(dp[i][j] != -1)return dp[i][j];
    
    //what option we have ,either to skip the value or untilise it 
    long long z = min(find(i+1,j+1,A,B)+abs(A[i]-B[j]),find(i,j+1,A,B));
    
    return dp[i][j] = z;
    
}

int main(){
    int t = 1;
    //cin>>t;
    
    while(t--){
          int n;
          cin>>n;
          
          int A[n];
          vector<int>C,D;
          for(int i=0;i<n;++i){
              cin>>A[i];
              if(A[i])C.push_back(i);
              else D.push_back(i);
          }
          
          memset(dp,-1,sizeof(dp));
          long long ans = find(0,0,C,D);
          cout<<ans<<"\n";
          
    }
}
