/*
Platform :- leetcode
Time Complexity :- O(n*k*2)
*/
class Solution {
public:
    int dp[1001][101][2];
    
    //so we take care of three states
    //0 means we can buy 
    //1 means we can sell
    int find(int i,int k,int f,vector<int>&prices){
        
        if(k<=0)return 0;
        if(i<0)return 0;
        
        if(dp[i][k][f] != -1)return dp[i][k][f];
        
        if(f){
            //here we have just one option
            //we can sell it now or move to next
            int val = prices[i] + find(i-1,k-1,0,prices);
            val = max(val,find(i-1,k,f,prices));
            
            return dp[i][k][f] = val;
        }
        else{
            //here we have two options
            //either to buy now or let it go
            int val = -prices[i] + find(i-1,k,1,prices);
            val = max(val,find(i-1,k,0,prices));
            return dp[i][k][f] = val;
        }
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        reverse(prices.begin(),prices.end());
        
         memset(dp,-1,sizeof(dp));
        int n = prices.size();
        return find(n-1,k,0,prices);
    }
};
