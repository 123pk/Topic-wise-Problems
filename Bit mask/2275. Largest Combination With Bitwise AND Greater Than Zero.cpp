/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 293
Approach :- We find the frequenc of every bit and the most frequent bit (its frequency) is our required answer.
*/
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        
        vector<int>fre(32);
        for(auto&x:candidates){
            string temp = bitset<32>(x).to_string();
            reverse(temp.begin(),temp.end());
            for(int i=0;i<32 ;++i){
                fre[i]+=(temp[i]-'0');
                ans = max(ans,fre[i]);
            }
        }
        
        return ans;
    }
};
