/*
Platform :- CSES
Approach :- We will use ( recurison + memoistaion ) , for a current index 'i' we will get A[i+1] in our parameter , we will then check if absolute difference between 
            abs(A[i+1]-A[i]) <= 1 or not if it is greater than '1' then we cannot move forward as there is no array with such value , if it satisifies the condition 
            we move forward to i-1 and do similar stuff ,
            
            if(A[i] == 0) then we will try three values 'A[i+1]',' A[i+1]-1 ' and A[i+1]+1 , as these three value are the only ones which satisfy the conditon abs(A[i]-A[i+1) <= 1
            
*/
#include<bits/stdc++.h>
using namespace std;
 
/*
Motive :- To complete DP problem set of CSES
          Lets do it
          
Problem :- Array Description
 
Primary approach :- We will start from the end , we will pass one last value and index and array in our function
                   --> We want to  return no of valid array satisfying this
                   --> i,j --> ith index , jth value
*/
#define ll long long

ll mod = 1e9+7;
 
 
ll find(int i,int val,int lim,vector<int>&A,vector<vector<ll>>&dp){
    if(i == -1) return 1;
    if(i<-1)return 0;
    
    //if(val<0 || val>lim)return 0;
    
    if(dp[i][val] != -1)return dp[i][val];
    
    //now what options do we have we can have only three values at max
    //val-1,val,val+1
    //this is also valid if we have zero
      
         if(A[i]){
             if(abs(A[i]-val) <= 1)return dp[i][val] = find(i-1,A[i],lim,A,dp)%mod;
             else return dp[i][val] = 0;
             
         }
         else{
           ll tot = 0;
           
           if((val-1)>=1)tot +=  find(i-1,val-1,lim,A,dp)%mod;
           if((val+1)<=lim)tot += find(i-1,val+1,lim,A,dp)%mod;
           tot += find(i-1,val,lim,A,dp)%mod;
           
            
           return dp[i][val] = tot%mod;
         }
      
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    vector<int>A(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,-1ll));
   // memset(dp,-1,sizeof(dp));
    ll ans = 0;
    if(A[n-1] == 0){
        for(int i=1;i<=m;++i){
            ans = ans + find(n-2,i,m,A,dp);
            ans%= mod;
        }
    }
    else{
        ans = find(n-2,A[n-1],m,A,dp)%mod;
    } 
    cout<<ans;
}
