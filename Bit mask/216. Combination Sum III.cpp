/*
Platform :- Leetcode
Approach :- First we will try all the possible combination of choosing 'k' values from '1' to '9' and if the sum is equal to 'n' we will push it in our answer.
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans,z;
        vector<int>temp;
        vector<int>A={1,2,3,4,5,6,7,8,9};
        
        //fisrt try all values 
        int lim = 1<<9;
        for(int i=1;i<=(lim);++i){
            int tot = 0;
            int c = 0;
            temp.clear();
            for(int j = 0;j<9;++j){
                if(i & (1<<j)){
                    tot+=A[j];
                    c++;
                    temp.push_back(A[j]);
                }
            }
            
            if(c == k && tot == n){
                ans.push_back(temp);
            }
        }
        
         
        
        return ans;
    }
};
