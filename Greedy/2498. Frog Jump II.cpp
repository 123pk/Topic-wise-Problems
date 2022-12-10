/*
Platform :- Leetcode
Contest :- Bi Weekly contest 93
Approach :- If you will observe you will find that it is Not Optimal to skip two consecutive rocks, so either we can start with '1' or '2' and get all the
            alternating rocks from there after and find the max value.
Time Complexity :- O(n)
*/
class Solution {
public:
    int maxJump(vector<int>& stones) {
        //if he ujumpth on ith stone or skip it
        int ans = 0;
        int last = 0;
        int n = stones.size();
        //starting from second
        vector<int>mark(n);
        for(int i=1;i<stones.size();i+=2){
            mark[i]++;
            if(i == 1)ans = max(ans,stones[i]);
            else ans = max(ans,stones[i]-stones[i-2]);
            last = i;
        }
        ans = max(ans,stones[n-1]-stones[last]);
        
        //we start from 3rd
        last = n-1;
        
        for(int i=n-2;i>=0;--i){
            if(mark[i] == 0){
                ans = max(ans,stones[last]-stones[i]);
                last = i;
            }
        }
        ans = max(ans,stones[last]);
        
        int ans2 = 0;
        vector<int>mark2(n);
        last = 0;
        
        for(int i=2;i<n;i+=2){
            mark2[i]++;
            ans2 = max(ans2,stones[i]-stones[last]);
            last = i;
        }
        
        ans2 = max(ans2,stones[n-1]-stones[last]);
        last = n-1;
        for(int i=n-2;i>=0;--i){
            if(mark2[i] == 0){
                ans2 = max(ans2,stones[last]-stones[i]);
                last = i;
            }
        }
        ans2 = max(ans2,stones[last]);
        
        ans = min(ans,ans2);
        return ans;
    }
};
