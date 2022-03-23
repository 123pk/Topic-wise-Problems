/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 74
Approach :- We will use dp for memoisation , so basic idea is to use dp[1000][1000] , such tha dp[i][j] stores the min no of white tiles that are remaining upto 'ith'
            index after using 'j' black tiles .
            We have two options ,either to put a tile at ith index or not , if we don't put it at ith index and 's[i] = '1'' then we have one uncoverd white tile.
            min of two option we return.
*/
class Solution {
public:
    int dp[1000][1001];
    
    int find(int idx,int rem,int len,string&s){
        if(idx<0)return 0;
        
        if(dp[idx][rem]!=-1){
            return dp[idx][rem];
        }
        
        int ans = INT_MAX;
        if(rem){
            ans = min(ans,find(idx-len,rem-1,len,s));    
        }
        
        int x = s[idx]-'0';
        ans = min(ans,find(idx-1,rem,len,s)+x);
        
        return dp[idx][rem] = ans;
        
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp,-1,sizeof(dp));
        int n = floor.size();
        return find(n-1,numCarpets,carpetLen,floor);
        
    }
};
