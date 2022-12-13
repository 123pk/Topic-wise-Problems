
 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& dist) {
        int n = dist.size();
        int m = dist[0].size();
        
         
        int temp=0;
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                 temp = dist[i-1][j]+dist[i][j];
                
                if((j+1)<m){
                    temp = min(dist[i-1][j+1]+dist[i][j],temp);
                }
                
                if((j-1)>=0){
                    temp = min(dist[i-1][j-1]+dist[i][j],temp);
                }
                dist[i][j]=temp;
            }
        }
        
        int ans = INT_MAX;
        for(int i=0;i<m;++i){
            ans = min(ans,dist[n-1][i]);
        }
        return ans;
    }
};
