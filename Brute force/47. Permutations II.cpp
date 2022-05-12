/*
Platform :- Leetcode
Approach :- We will first sort the array and then will use built in function "next_permutaion" on do - while loop to get all the possible permutaions
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        
        do{
            ans.push_back(nums);
        }
        while(next_permutation(nums.begin(),nums.end()));
        
        return ans;
    }
};
