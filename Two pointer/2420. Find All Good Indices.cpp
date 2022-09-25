/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 312
Approach :- We will try to find length of of longest non-increasing subarray till 'ith' index and similarly length of longest non-decreasing subarray .
            We will use prefix and suffix array to do so .
            Now for each index we will check the condition and if it satisfies then it is peak else not .
Time Complexity :- O(N)
*/
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref(n),suff(n);
        
        vector<int>ans;
        
        int c = 0;
        for(int i=0;i<n;++i){
            if(i == 0){
                c = 1;
                //pref[i] = c;
            }
            else{
                if(nums[i]<=nums[i-1]){
                    c++;
                }
                else{
                    c = 1;
                }
            }
            pref[i] = c;
        }
        
        
        c = 0;
        for(int i=n-1;i>=0;--i){
            if(i == n-1){
                c=1;
            }
            else{
                if(nums[i]<=nums[i+1]){
                    c++;
                }
                else c = 1;
            }
            suff[i] = c;
        }
        
        for(int i=k;i<(n-k);++i){
            if(pref[i-1]>=k && suff[i+1]>=k){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
