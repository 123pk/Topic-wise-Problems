/*
Platform :- Codeforces
Contest :- Codeforces Global Round 22
Approach :- We will use (0/1) dp (recursion + memoistaion) where we have two optioon for each player either to choose odd or even term if available .
             We will choose the options according to moves , bob will want alice to loose and alice will want to win.
*/
#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int find(int i,int odd,int eve,int have,int move){
    
    if(dp[odd][eve][have] != -1)return dp[odd][eve][have];
   // cout<<i<<" "<<odd<<" "<<eve<<" "<<move<<" "<<have<<"\n";
    
    if(i == 0){
        if(move%2){
            //bob turn 
           // if(have%2)cout<<" Winner is Bob\n\n";
          //  else cout<<" Winner is Alice\n\n";
            if(have%2)return dp[odd][eve][have] = 0;
            else return dp[odd][eve][have] = 1;
        }
        else{
            //alice turn
            if(odd){
                //If I have odd 
                if(have%2)return dp[odd][eve][have] = 1;
                else return dp[odd][eve][have] = 0;
            }
            else{
                if(have%2)return dp[odd][eve][have] = 0;
                else return dp[odd][eve][have] = 1;
            }
        }
    }
    else{
        //I wil check 
        //what to do
        if(move%2){
            //Bob turn
            int val = 1;
            if(odd){
                //he will choose odd
                val = find(i-1,odd-1,eve,have,move+1);
            }
            //I was able to get odd sum
            if(val == 0)return dp[odd][eve][have] = 0;
            
            if(eve)val = find(i-1,odd,eve-1,have,move+1);
            
            return dp[odd][eve][have] = val;
        }
        else{
            //it is alice turn
            int val = 0;
            
            if(odd){
                val = find(i-1,odd-1,eve,have+1,move+1);
            }
            if(val)return dp[odd][eve][have] = 1;
            val = 0;
            if(eve)val = find(i-1,odd,eve-1,have,move+1);
            return dp[odd][eve][have] = val;
        }
    }
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int c = 0,d = 0;
        long long A[n];
        for(int i=0;i<n;++i){
            cin>>A[i];
            if(A[i]%2)c++;
        }
        
        memset(dp,-1,sizeof(dp));
        
        if(find(n-1,c,n-c,0,0))cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}
