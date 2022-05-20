/*
Platform :- Leetcode
Approach :- Since we are allowed to have two moves only ,either go to "rigth" or to "down" , we will use 2D Dp , 
            where dp[i][j] ---> gives us no of ways to reach to this node from top left ,
            
            DP STATE --->   dp[i][j] = dp[i][j-1] + dp[i-1][j] , for j>=1 && j<m && i>=1 && i<n (0 - based indexing)
            -->here also if we have obstacle then dp[i][j] = 0,
            for j == 0  dp[i][j] = dp[i-1][j]
            for i == 0  dp[i][j] = dp[i][j-1]
            
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int ans=0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0||j==0){
                   if(obstacleGrid[i][j]==1)dp[i][j]=0;
                   else{if(i==0&&j==0)dp[i][j]=1;
                    else if(j==0)dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                    }
                }
                else{
                    if(obstacleGrid[i][j]==1)dp[i][j]=0;
                    else{
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        
       /* for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<dp[i][j]<<" ";
            }
             cout<<"\n";
        }*/
        return dp[n-1][m-1];
    }
};
