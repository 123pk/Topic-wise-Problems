/*
Platform :- Atcoder
Contest :- DP task
Approach :- For value in range from [1 to 10^5] we will find the min weight reaquired to reach upto that vaule and at the end we will find the max value which has required weight 
            is less that max weight
*/
#include<bits/stdc++.h>
using namespace std;

long long wt[101],val[101];
long long dp[101][100001];

long long find(int idx,long long value){
    if(value== 0)return 0ll;
    if(idx<0)return 1e18;
    
    
    
    if(dp[idx][value]!=-1)return dp[idx][value];
    
    long long ans =find(idx-1,value);
    if(value-val[idx]>=0)ans = min(ans,find(idx-1,value-val[idx])+wt[idx]);
    
    
    return dp[idx][value] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    long long w;
    cin>>n>>w;
    
    for(int i=0;i<n;++i)cin>>wt[i]>>val[i];
     
    
    for(int i=1e5;i>=0;--i){
        if(find(n-1,i)<=w){
            cout<<i<<"\n";
            break;
        }
    }
    
}
