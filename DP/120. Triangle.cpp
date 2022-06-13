/*
Platform :- Leetcode
Apporach :- For all level from 0 to n-2 , we will update the values at next level , for index from 1 to length of vector of ith level we will update all 
            values from 1 to len[i]-1 , 
            we will store the min (triangle[i+1][j] + triangle[i][j] , triangle[i+1][j]+triangle[i][j-1] ) 
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        
        //vector<vector<int>>temp = triangle;
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        
        for(int i=0;i<n-1;++i){
            triangle[i+1][0] += triangle[i][0];
            triangle[i+1][triangle[i].size()] += triangle[i][triangle[i].size()-1];
            
            for(int j=1;j<(triangle[i].size());++j){
                //we need to do this 
                int val = triangle[i+1][j];
                
                triangle[i+1][j] = min(val+triangle[i][j],val+triangle[i][j-1]);
            }
        }
        
        
        for(int i=0;i<m;++i){
            ans = min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};
