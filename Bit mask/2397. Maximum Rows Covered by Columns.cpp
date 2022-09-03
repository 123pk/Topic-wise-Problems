/*
Platform :- Leecode
Contest :- Leetcode Bi Weekly contest 86
Approach :- To get all the combination of rows using bitmask and then validtion of condition
Time Complexity :- O(2^n)
*/
class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
       int ans = 0;
        
        //so the approach is to choose combination of rows (usign bit manimpulation) and then find 
        //total number of colums we need to choose , let that value be 'x' and if x<=cols ,
        //it is a valid combinatino and we store the score which is no of rows choosen
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=1;i<=(1<<n);++i){
            int d = 0;
            vector<int>req(m);
            
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    //if jth row is choosen
                    //I find the columns required
                    for(int k=0;k<m;++k){
                        if(mat[j][k]){
                            req[k]++;
                        }
                    }
                    d++;
                    //this stores the no of rows 
                }
            }
            
            int c = 0;
            for(int i=0;i<m;++i){
                if(req[i])c++;
            }
            //if no of columsn is less than equal to allowed cols
            if(c<=cols){
                ans = max(ans,d);
            }
        }
        
        return ans;
    }
};
