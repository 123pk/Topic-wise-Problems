/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 135
Approach :- So we have four combination to take care for any range [i,j]
            1. If Alice choose ith element 
                  i. When Bob chooses (i+1)th element
                  ii. When Bob Choses (jth) element
            2. If Alice choose jth element 
                  iii. When Bob Chooses (i)th element
                  iv. When Bob choose (j-1)th element
            So we will use ' recursion+ memoisation' (DP) and find suitable situation for all the four conditions
Time Complexity :- O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001];

int find(int i,int j,string&s){
    
    if((j-i) == 1){
        if(s[i] == s[j])return dp[i][j] = 0;
        return dp[i][j] = 1;
    }
    
    if(dp[i][j] != -1)return dp[i][j];
    
    //we have two options either to choose value from front
    //if bob choose the first element from
    int val1 = find(i+2,j,s);
    
    //if bob chooses the last element
    int val2 = find(i+1,j-1,s);
    //cout<<i<<" "<<j<<" "<<val1<<" "<<val2<<" *\n";
    
    
    if(val1 == 1&& val2 == 1)return dp[i][j] = 1;
    
    if(val1 == 2 || val2  == 2)return dp[i][j] = 2;
    
    if(val1){
        if(s[i]<s[j])return dp[i][j] = 1; 
    }
    
    if(val2){
        if(s[i]<s[i+1])return dp[i][j] = 1;
    }
    
    if(val2 == 0){
        if(s[i]!=s[j])return dp[i][j] = 1;
    }
    
    if(val1 == 0){
        if(s[i]<s[i+1])return dp[i][j] = 1;
    }
    
    //now if he choose the last option
    val1 = find(i+1,j-1,s);
    val2 = find(i,j-2,s);
    //cout<<i<<" "<<j<<" "<<val1<<" "<<val2<<"\n";
    
    
    if(val1 == 1 && val2 == 1)return dp[i][j] = 1;
    
    if(val1 ==2 || val2 == 2)return dp[i][j] = 2;
    
    if(val1){
        if(s[j]<s[j-1])return dp[i][j] = 1;
    }
    
    if(val2){
        if(s[j]<s[i])return dp[i][j] = 1;
    }
    
    if(val1 == 0){
        if(s[i]!=s[j])return dp[i][j] = 1;
    }
    
    if(val2 == 0){
        if(s[j]<s[j-1])return dp[i][j] = 1;
    }
    
    return dp[i][j] = 0;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        
        int val = find(0,n-1,s);
        if(val == 0)cout<<"Draw\n";
        else if(val == 1)cout<<"Alice\n";
        else cout<<"Bob\n";
        
    }
}
