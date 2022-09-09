/*
Platform:- Leetcode
Approach :- Okay so we have two posibilities for each cell either we are at top ( upper part of the line ) or (bottom part of line ).
            So we do go from bottom to up and store the column cell if we are able to reach the very top.
*/
class Solution {
public:
    //it stores if the ball is at index i,j is it possible to reach to botto
    int dp[101][101][2];
    
    int find(int i,int j,int k,vector<vector<int>>&grid){
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        if(i == 0 ){
            if(k == 1)return dp[i][j][k] = j+1;
            else {
                 //now it will depend on my move 
                 if(grid[i][j] == 1){
                    if(j == 0)return dp[i][j][k] = 0;
                    else{
                        if(grid[i][j-1] == 1){
                            return dp[i][j][k] = find(i,j-1,1-k,grid);
                        }
                        else{
                            return dp[i][j][k] = 0;
                        }
                    }
                 }
                else{
                    if(j == grid[0].size()-1)return dp[i][j][k] = 0;
                    else{
                        if(grid[i][j+1] == -1){
                            return dp[i][j][k] = find(i,j+1,1-k,grid);
                        }
                        else return dp[i][j][k] = 0;
                    }
                }
            }
        }
        else{
            if(k == 0){
                if(grid[i][j] == 1){
                    if(j == 0)return dp[i][j][k] = 0;
                    else{
                        if(grid[i][j-1] == 1){
                            return dp[i][j][k] = find(i,j-1,1-k,grid);
                        }
                        else{
                            return dp[i][j][k] = 0;
                        }
                    }
                }
                else{
                    if(j == grid[0].size()-1)return dp[i][j][k] = 0;
                    else{
                        if(grid[i][j+1] == -1)return dp[i][j][k] = find(i,j+1,1-k,grid);
                        else return dp[i][j][k] = 0;
                    }
                }
            }
            else{
                return dp[i][j][k] = find(i-1,j,1-k,grid);
            }
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans(m,-1);
        
        for(int i=0;i<grid[0].size();++i){
            if(i == 0){
                if(grid[n-1][0] == 1)continue;
            }
            if(i == m-1){
                if(grid[n-1][i] == -1)continue;
            }
            
            int z = find(n-1,i,0,grid);
            if(z){
                ans[z-1] = i;
            }
        }
        return ans;
    }
};
