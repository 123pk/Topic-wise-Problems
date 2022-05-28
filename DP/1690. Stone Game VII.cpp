/*
Platform :- Leetcode
Approach :- We will use dp , as we have two option either to remove one element from the left or from the extreme right of available stone array .
            we will try to get the the max difference we can get if we choose the first element or last element and we return that value .
            
*/
class Solution {
public:
    int dp[1001][1001];
    
    int find(int start,int end,vector<int>&pref,vector<int>&stones){
        if(start>end)return 0;
        
        if((start+1) == end)return max(stones[start],stones[end]);
        
        if(dp[start][end]!=-1)return dp[start][end];
        
        //if we choose the first element to remove
        int value1 = (pref[end] - pref[start])-find(start+1,end,pref,stones);
            
        //if we choose the last element to remove
        int value2 = pref[end-1];
        if(start)value2-=pref[start-1];
        value2 -= find(start,end-1,pref,stones);
            
        return dp[start][end] = max(value1,value2);
    }
    
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        int n = stones.size();
        
        int tot = 0;
        vector<int>pref(n);
        for(int i=0;i<n;++i){
            tot += stones[i];
            pref[i] = tot;
        }
        return find(0,n-1,pref,stones);
    }
};
