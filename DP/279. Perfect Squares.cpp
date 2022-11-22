/*
Platform :- Leetcode
Approach :- let 'x' be square root of 'i' , we will use dp here where dp[i] = min number of perfect squre sum who add to 'i',
            so we will run aloop from 'j' -- (1 to 'x') for each 'i' and will find the min cost out of them all which will be '(dp[i] = min(dp[i],dp[i-j]+1)'
Time Complexity :- O(n*sqrt(n))
*/
class Solution {
public: 
 

    int numSquares(int n) {
        int ans = 0;
        
        //we need to know about this 
        vector<int>dp(n+1,INT_MAX);
          
        dp[0] = 0;
        for(int i=1;i<=n;++i){

            for(int j=1;j*j<=i;++j){
                int val = j*j;
                 
                dp[i] = min(dp[i],dp[i-val]+1);
            }
       //    cout<<"\n";
        }

        return dp[n];
    }
};
