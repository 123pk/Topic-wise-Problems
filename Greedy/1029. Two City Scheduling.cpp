/*
Platform :- Leetcode
Approach :- We will first send every passanger to city 1, we will also compute the difference in cost of travelling to city 1 than city 2 , then we will sort the arrray
            and smallest 'n' values will be added to our cost that will depict that thos passangers are sent to city 2 . It is optimal as in this way we will thos passangers
            for city 2 whose fair for city 1 > city2 .
*/
class Solution {
public:
     
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        int tot = 0;
        vector<int>dif;
        for(auto&x:costs){
            dif.push_back(x[1]-x[0]);
            tot+=x[0];
        }
        sort(dif.begin(),dif.end());
        int n = costs.size();
        n>>=1;
        for(int i = 0;i<n;++i){
            tot+=dif[i];
        }
        ans = tot;
        return ans;
    }
};
