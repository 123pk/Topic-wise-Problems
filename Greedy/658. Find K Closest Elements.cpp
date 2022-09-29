/*
Platform :- Leetcode
Approach :- Find the abs diff and store it along with value and now sort them in increasing order and get the kth value
Time Complexity :- O(n Logn)
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int y) {
        vector<int>ans;
        vector<pair<int,int>>P;
        for(auto &x:arr){
            P.push_back({abs(x-y),x});
        }
        
        sort(P.begin(),P.end());
        
        for(int i=0;i<k;++i)ans.push_back(P[i].second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
