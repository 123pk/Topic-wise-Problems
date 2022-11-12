/*
Platform :- Coding Compeition with google
Contest :- Google Kickstart Round H
Approach :- So we will traverse though from 1 to n and for each i, we will find the minimum coins we will need to get 'i' lilies out of the well ,
            you need to notice that you get minimum cost if you choose some factor of 'i' and take note of it and then repeatedly use that many using '2' coins .
            And if its is prime number them dp[i] = min(dp[i],dp[i-1]+1)
Time Complexity :- O(n* sqrt(n))
*/
#include<bits/stdc++.h>
using namespace std;

int find(int n,int i){
    int score = n;
    int cur = (n/i);
    int val = (cur+1)*2;
    int z = cur*i;
    val += (n - z);
    score = min(score,val);
    return score;
}
 
int main(){
    int t;
    cin>>t;
    
    for(int z=1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        
        if(n<=5){
            cout<<n<<"\n";
            continue;
        }
        vector<int> dp(n+1,n);
        for(int i=1;i<=n;++i){
            //all the factors
            int val = i;
            for(int j=2;j*j<=i;++j){
                if(i%j == 0){
                    int f = i/j;
                    val = min(val,find(i,f)+dp[f]);
                    val = min(val,find(i,j)+dp[j]);
                }
            }
            dp[i] = min(dp[i],val);
            dp[i] = min(dp[i],dp[i-1]+1);
        }
       // cout<<score[48]<<" ";
        cout<<dp[n]<<"\n";
    }
}
