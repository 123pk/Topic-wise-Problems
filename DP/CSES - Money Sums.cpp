/*
Platform :- CSES
Approach :- We will use 'dp[n][100001]' , so we have 'n' values and we can use them one in any subset , so what we willd o is we will run a loop from 0 to n
            then inside the loop we will run from '0' to max_sum possible and will check if (j-A[i]) is already reached then we can reach [i][j] .
*/
#include<bits/stdc++.h>
using namespace std;
 
  
int main(){
    int n;
    cin>>n;
    
    vector<int>A(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    
    sort(A.begin(),A.end());
    vector<int>temp;
    int dp[n+1][100001]={0};
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        
        for(int j=0;j<=100000;++j){
            //if we can achieve till 'j' sum in previous value thne we can acheive it now also
            dp[i][j] = dp[i-1][j];
            
            //else we will check if 'j' - A[i-1] is reachable or not
            int prev = j - A[i-1];
            if(prev>=0 && dp[i-1][prev]){
                dp[i][j] = 1;
                
            }
        }
    }
    
    
     
        for(int j=1;j<=100000;++j){
            if(dp[n][j])temp.push_back(j);
        }
     
     
    
    cout<<temp.size()<<"\n";
    for(auto&x:temp)cout<<x<<" ";
    cout<<"\n";
}
