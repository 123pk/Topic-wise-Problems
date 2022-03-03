/*
Platform :- Leetcode
Approach :- We try to find length of arithmetic subarray , for a arithmetic array of length of 'c' we can have (c*(c+1))/2 subarrays . So we find that 'c' while traverseing through
            the array and maintain one value 'c' which we increment if (A[i]-A[i-1] == dif) else we add (c*(c+1))/2 to our answer and make c = 0 and (dif = A[i]-A[i-1])
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        if(nums.size()<3)return ans;
        int c= 0;
        int dif = nums[1]-nums[0];
        for(int i=2;i<nums.size();++i){
            if((nums[i]-nums[i-1])==dif){
                c++;
                if(i==nums.size()-1){
                    ans+=(c*(c+1))/2;
                }
            }
            else{
                ans+=(c*(c+1))/2;
                dif = nums[i]-nums[i-1];
                c=0;
            }
        }
        
        return ans;
    }
};
