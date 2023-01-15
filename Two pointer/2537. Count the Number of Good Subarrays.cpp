/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 328
Approach :- We want to find no of subarrays satifying the following condition starting at index 'i' for all ( 0 <= 'i' < n )
            We maintian one score which store the no of such pairs,once 'score' >= k , we will move the start pointer which is pointing to the start of the current subarray
            moving a start pointer will cost us fre[nums[start]]-1 , where fre store the frequency of values of arrays till now.
Time Compelxity :- O(n log n)
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        
        map<long long,long long>fre;
        int start = 0; 
        long long score = 0,sz = nums.size();
        long long req = k;
        
        set<pair<long long,long long>>P;
        for(long long i=0;i<nums.size();++i){
            fre[nums[i]]++;
            long long cur = fre[nums[i]];
            score += (cur-1);
            if(score>=k){
            
                ans += (sz-i);
                //cout<<ans<<" ";
                while(score>=k){
                    score -= (fre[nums[start]]-1);
                    fre[nums[start]]--;
                    if(score>=k){
                        ans += (sz-i);
                    }
                    start++;
                }
            }
        }
        
        return ans;
    }
};
