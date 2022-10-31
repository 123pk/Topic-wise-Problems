
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //first check for th upper half 
        int i = 0,j;
        int n = matrix.size();
        int m = matrix[0].size();
        for(j=0;j<m;++j){
            int s = i+1,e = j+1;
            while(s<n && e<m){
                if(matrix[s-1][e-1] !=  matrix[s][e])return false;
                s++;
                e++;
            }
        }
        
        j = 0;
        for(int i=1;i<n;++i){
            int s = i+1;
            int e = j+1;
            while(s<n && e<m){
                if(matrix[s-1][e-1] !=  matrix[s][e])return false;
                s++;
                e++;
            }
        }
        
        return true;
    }
};
