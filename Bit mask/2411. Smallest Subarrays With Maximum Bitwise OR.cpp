/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 87
Approach :- So traverse from last to front and maintain one array of bits and one array whcih store the smallest index that set that bit 
            Now for eachindex the length of smallest subarray is max_value of smallest indexes for each bit - i.
*/
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        //for each of set bit I want to find the smallest index which sets it 
        vector<int>set_bit(32);
        vector<int>idx(32);
        
        for(int i=n-1;i>=0;--i){
            string temp = bitset<32>(nums[i]).to_string();
            reverse(temp.begin(),temp.end());
            
            for(int j=0;j<32;++j){
                if(temp[j] == '1' && set_bit[j] == 0){
                    //so this is the smallest index that sets this bit
                    idx[j] = i+1;
                }
                else{
                    //if the bit is seet
                    if(temp[j] == '1'){
                        idx[j] = i+1;
                    }
                }
            }
            
            //now out of all 32 bits 
            //we choose the max index of set bit
            int mx = 0;
            for(int j=0;j<32;++j){
                mx = max(mx,idx[j]);
            }
            
            ans[i] = max(1,mx - i);
        }
        return ans;
    }
};
