/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 271
Approach :- We will first come up with recursiv solution where we will use both the option and later we will use memoisation to avoid TLE.
             So we have two opton 
             i. Choose value at top
             ii. Flip the top and get the bottom value
Time Complexity :- O(n*k)
*/
#include<bits/stdc++.h>
using namespace std;

string ans = "";
string temp = "";
int dp[101][10001];

int find(int i,int req,vector<int>&A,vector<int>&B,string cur){
    
    if(dp[i][req] != -1)return dp[i][req];
    
    if(i == 0){
        if(A[i] == req){
            if(ans.size() == 0){
                ans =  cur;
                ans += 'H';
            }
            return dp[i][req] = 1;
        }
        else if(B[i] == req){
            if(ans.size() == 0){
                ans =  cur;
                ans += 'T';
            }
            return dp[i][req] = 1;
        }
        else return dp[i][req] = 0;
    }
    else{
         
            //two option 
             
            int val;
            
            //we choose front value
            val = 0;
            if(A[i]<req){
                temp = "";
                temp = cur;
                temp += 'H';
                val = find(i-1,req-A[i],A,B,temp);
            }
            
            if(val)return dp[i][req] = 1;
            //we choose back value
            if(B[i]<req){
                temp = "";
                temp = cur;
                temp += 'T';
                val = find(i-1,req-B[i],A,B,temp);
            }
            
            return dp[i][req] = val;
            
         
    }
}


int main(){
    int n,s;
    cin>>n>>s;
    
    vector<int>A(n),B(n);
    for(int i=0;i<n;++i){
        cin>>A[i]>>B[i];
    }
    
    memset(dp,-1,sizeof(dp));
    int val = find(n-1,s,A,B,"");
    
    if(val){
        cout<<"Yes\n";
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
    else cout<<"No\n";
    
}
