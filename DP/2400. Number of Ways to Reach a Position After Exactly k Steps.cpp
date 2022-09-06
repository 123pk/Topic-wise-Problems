/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 309
Approach :- We will use recursion + memoisation (dp) , as it is one of standard problems where dp[i][j] --> gives us the number of ways to reach (ith coordinate) with 
            'k' steps .
            Before applying this we need to take care of negative values , we will add 1000 to both 'start' and 'end' so that they will not be negative
Time Complexity :- O(n*k) , where n can be atmax 3000
*/

class Solution {
public:
    int mod = 1e9+7;
    int dp[3001][1001];
    long long find(int cur,int target,int k){
        
        if(k == 0 && cur == target)return 1;
        if(k == 0 && cur != target)return 0;
        
        if(dp[cur][k] != -1)return dp[cur][k];
        
        long long val = find(cur-1,target,k-1) + find(cur+1,target,k-1);
        
        return dp[cur][k] = val%mod;
    }
    
    int numberOfWays(int start, int end, int k) {
        int mod = 1e9+7;
        int dif = abs(end - start);
        if(dif>k)return 0;
        
        int extra = (k-dif);
        if(extra%2)return 0;
         start = abs(start);
        end = abs(end);
        
        start+=1000;
        end += 1000;
        
         
        
        //cout<<start<<" "<<end<<" "<<k<<"\n";
        
        memset(dp,-1,sizeof(dp));
        
        //what to do 
        return find(start,end,k);
    }
};
