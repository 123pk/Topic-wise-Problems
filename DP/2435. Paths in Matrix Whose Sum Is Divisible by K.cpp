/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 314
Appraoch :- We will use dp here , dp[i][j][k] ,this will store number of ways to get 'remainder' of sum equal to 'k' at cell (i,j) . 
            -- since there cannot be value of k>=50 , we can use this
Time and Space complexity :- O(n*m*k) .
*/
class Solution {
public:
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m][k];
        int mod = 1e9+7;
        
        
        //now of ways I can get the mod%k = l till i,j
        
        memset(dp,0,sizeof(dp));
        
         
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int val = grid[i][j];
                if(i == 0 && j == 0){
                    dp[i][j][val%k] = 1;
                }
                else if(i == 0){
                    for(int l=0;l<k;++l){
                        int cur = val + l;
                        cur%=k;
                        dp[i][j][cur] += dp[i][j-1][l];
                        dp[i][j][cur]%=mod;
                    }
                }
                else if(j == 0){
                    for(int l=0;l<k;++l){
                        int cur = val + l;
                        cur%=k;
                        dp[i][j][cur] += dp[i-1][j][l] ;
                        dp[i][j][cur]%=mod;
                    }
                }
                else{
                    
                    for(int l=0;l<k;++l){
                        int cur = val + l;
                        cur%=k;
                        dp[i][j][cur] += dp[i-1][j][l]; 
                        dp[i][j][cur]%=mod;
                        dp[i][j][cur] +=dp[i][j-1][l];
                        dp[i][j][cur]%=mod;
                    }
                }
            }
        }
        
        return dp[n-1][m-1][0];
    }
};
