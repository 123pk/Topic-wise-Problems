/*
Platform :- Leetcode
Approach :- Greedy
Time Complexity :- O(n log n)
*/
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        
        int ans = 0;
        int i = 0;
        for(auto&x:capacity){
            x = x - rocks[i];
            i++;
        }
        
        sort(capacity.begin(),capacity.end());
        for(int i = 0;i<capacity.size() && add>0;++i){
            if(capacity[i]<=add){
                ans++;
                add-=capacity[i];
            }
            else break;
        }
        
        
        return ans;
    }
};
