
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>unq;
      int n = nums.size();
      
       for(int i=1;i<=(1<<n);++i){
           int last = -1000;
           int f = 0;
           vector<int>temp;

           for(int j=0;j<n;++j){
               if(i & (1<<j)){
                  if(last<=nums[j]){
                      last = nums[j];
                  }
                  else{
                       f = 1;
                       break;
                  }
                  temp.push_back(nums[j]);
               }
           }

           if(f || temp.size()<=1){
               temp.clear();
               continue;
           }
           else {
               if(unq.size()==0){
                  ans.push_back(temp);
                  unq.insert(temp);
               }
               else{
                   if(unq.find(temp)==unq.end()){
                       ans.push_back(temp);
                       unq.insert(temp);
                   }
               }
           }
           temp.clear();
       }
        
        return ans;
    }
};
