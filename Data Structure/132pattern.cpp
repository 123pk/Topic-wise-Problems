/*
Platform :- Leetcode
Approch :- We will maintain a prefix array where 'pref[i]' will store the minimum value till ith index , now we will maintain a set to store values in increasing order
           from behind (last to first) , now basic idea is to check for all values from (1 to n-2) that for value 'nums[i]' if we have a value in set which is greater
           than pref[i-1] and less than nums[i] , 
           so let 'x' be the value in set then we want , pref[i-1] < x  < nums[i] , we will use lower_bound on set to find the just greater value than pref[i-1], if there
           exist any such value then we will  return true.
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        //so we will store prefix of min value for all index
        int n = nums.size();
        vector<int>pref(n);
        int mx = INT_MAX;
        
        for(int i=0;i<n;++i){
            mx = min(mx,nums[i]);
            pref[i] = mx;
        }
        
        set<int>largest;
        
        for(int i=n-1;i>0;--i){
            if(i == n-1){
                largest.insert(nums[i]);
                continue;
            }
             
            //now if we have any value which is greater than smallest value till i-1
            //and smaller than current value in set then we can have the condition satisfied
            auto it = largest.lower_bound(pref[i-1]);
            
            if(it == largest.end()){
                largest.insert(nums[i]);
                continue;
            }
            int val = *it;
            if(val == pref[i-1])it++;
            if(it == largest.end()){
                largest.insert(nums[i]);
                continue;
            }
            
            val = *it;
            
            if(val<nums[i])return true;
            largest.insert(nums[i]);
            
            
            
        }
        return false;
    }
};
