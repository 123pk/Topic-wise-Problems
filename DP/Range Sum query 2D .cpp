/*
Platform :- Leetcode
Approach :- We will precalculate the sum till (i,j) ,
           --> sum of all values from 
               from 0 to i
                   from 0 to j
                       sum += matrix[i][j]
              We will do it optimally . 
              The best way to get the sum is dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
              we have subtracted dp[i-1][j-1] because it is repeating in both i,j-1 and i-1,j
              
              Similarly to find value from (i1,j1) to (i2,j2) , we will get it by val = dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1]
*/
class NumMatrix {
public:
    vector<vector<int>>pref_sum;
   // vector<vector<int>>suff_sum;
    
    int tot_sum = 0;
    //basic approach is to find the 
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        pref_sum.resize(n,vector<int>(m));
       // suff_sum.resize(n,vector<int>(m));
        
        //now get the sum 
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                tot_sum += matrix[i][j];
                
                if(i == 0 || j == 0){
                    if(i == 0 && j == 0){
                        pref_sum[i][j] = matrix[i][j];
                    }
                    else if(i == 0){
                        pref_sum[i][j] = pref_sum[i][j-1] + matrix[i][j];
                    }
                    else pref_sum[i][j] = pref_sum[i-1][j] + matrix[i][j];
                }
                else{
                    //else get the sum as i-1,j and i,j-1 and remove i-1,j-1 
                    //that is added twice
                    pref_sum[i][j] = matrix[i][j] + pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1];
                }
            }
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //now if we want the region it is 
        //the sum of suff[i][j] + pref[i][j] - tot
        int val = pref_sum[row2][col2];
        
        if((row1-1)>=0)val-=pref_sum[row1-1][col2];
        if((col1-1)>=0)val-=pref_sum[row2][col1-1];
        if((row1-1)>=0 && (col1-1)>=0)val+=pref_sum[row1-1][col1-1];
        
        return val;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
