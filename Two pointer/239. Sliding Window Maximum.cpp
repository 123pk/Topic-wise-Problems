/*
Platform :- Leetcode
Approach :- We will maintain one frequency array and one set which will give us the largest value in current subarray from index [l,r] , we will use sliding window and
            update the frequency as we go on , if frequency of element becomes zero we will erase it from the array
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        
        //we need one frequency count array
        //one set to find the max value
        map<int,int>fre;
        set<int>large;
        for(int i=0;i<k;++i){
            fre[nums[i]]++;
            large.insert(nums[i]);
        }
        auto it = large.end();
        it--;
        ans.push_back(*it);
        for(int i=k;i<nums.size();++i){
            // remove the last element if the fre = 0
            fre[nums[i-k]]--;
            if(fre[nums[i-k]] == 0)large.erase(nums[i-k]);
            fre[nums[i]]++;
            large.insert(nums[i]);
            auto it2 = large.end();
            it2--;
            ans.push_back(*it2);
        }
        
        return ans;
    }
};
