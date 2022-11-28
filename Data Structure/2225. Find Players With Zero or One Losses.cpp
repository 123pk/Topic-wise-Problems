/*
Platform :- Leetcode
Time Complexity :- O(n log n)
Approach :- We maintain count array which stores the count of matches 'x'th player lost, we maintain one set which stores the players which played .
            Now we traverse through the set and get those values in first array which have ( count[x] == 0),
            if we have count[x] == 1,we push in second array.

*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>losser;
        set<int>played;

        for(auto&x:matches){
            played.insert(x[0]);
            played.insert(x[1]);
            losser[x[1]]++;
        }

        vector<vector<int>>ans(2);

        for(auto&x:played){
            if(losser[x] == 0)ans[0].push_back(x);
            else if(losser[x] == 1)ans[1].push_back(x);
        } 
 

        return ans;
    }
};
