/*
Platform :- Leetcode
Approach :- So the intution is that you need to understand if there are 'x' number of consecutive same colors then we need to remove 'x-1' of them for 'x'>1 ,
            so we will choose the one with max_time out of those 'x' to be left out and we will remvove all the remainings ones.
            So approach is to find consecutive equal colors range and remove the max from sum of range .
            We can use prefix sum or we can store the last index with number of consecutive terms and store in array , later we traverse throught the range and find 
            the sum of time in range and remove the max time from the sum of range and that remaining time is added to our answer.
Time Complextiy :- O(n)
*/
class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int ans = 0;
        
        int n = need.size();
        
        vector<pair<int,int>>change;
        //index and no of consecutive values that are equal
        int c = 1;
        
        for(int i=1;i<n;++i){
           if(colors[i] == colors[i-1]){
               c++;
               if(i == n-1)change.push_back({i,c});
           }     
            else{
                if(c>1){
                    change.push_back({i-1,c});
                }
                c = 1;
            }
        }
        
        
        for(auto&x:change){
            int tot1 = 0;
            int idx = x.first;
            int mn = 0;
            //find sum in range and remove the max value in range from it
            for(int i=0;i<x.second;++i){
                tot1 += need[idx-i];
                mn = max(mn,need[idx-i]);
            }
            
            ans += (tot1 - mn);
        }
        
        return ans;
    }
};
