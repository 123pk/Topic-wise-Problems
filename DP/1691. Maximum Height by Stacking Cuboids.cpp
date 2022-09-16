/*
Platform :- Leetcode
Qualtiy :- Very Good
Approach :- We first sort the dimennsions of array in increasing order as we can rotate in any direction and can make any type of box,
            now we sort the values off finaly array in increasing order .
            If you can broadly see then this problem is now reduced down to finding the LIS of the 2-D array .
            So we use Dp to find LIS in O(n^2)
Time Complexity :- O(n^2)
*/

bool comp(vector<int>&P,vector<int>&Q){
    if(P[2] == Q[2]){
        if(P[1] == Q[1])return P[0]>Q[0];
        return P[1]>Q[1];
    }
    return P[2]>Q[2];
}

class Solution {
public:
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto&x:cuboids)sort(x.begin(),x.end());
        
        sort(cuboids.begin(),cuboids.end(),comp);
        for(auto&x:cuboids)reverse(x.begin(),x.end());
        reverse(cuboids.begin(),cuboids.end());
        //now can I use dp ?
        //Yes I can 
         
        int n = cuboids.size();
       
        int mx = 0;
        vector<int>dp(n,0);
        for(int i=0;i<n;++i){
            dp[i] = cuboids[i][0];
            mx = max(mx,dp[i]);
            
             //finding LIS 
            for(int j=i-1;j>=0;--j){
                //check if this box can come inside ith vos or not
                if((cuboids[i][0]<cuboids[j][0]) || (cuboids[i][1]<cuboids[j][1]) || (cuboids[i][2]<cuboids[j][2]))continue;
                
                if(dp[i]<(dp[j]+cuboids[i][0])){
                    dp[i] = dp[j]+cuboids[i][0];
                    mx = max(mx,dp[i]);
                }
            }
        }
        return mx;
    }
};
