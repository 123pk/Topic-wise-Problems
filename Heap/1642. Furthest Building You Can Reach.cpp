/*
Platform :- Leetcode
Approach :- We will maintain a max heap and we will add the amount of bricks required when A[i]>A[i-1] , we will add (A[i]-A[i-1]) to our sum , if the (sum>limit)
            then we remove the max value of required brick till current index and will increment the count of such operation , if the count > 'k' we break out of loop.
            and the last index-1 is our answer.
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int ans = 0;
        int n = heights.size();
        int tot = 0,i;
        priority_queue<int>P;
        for(i=1;i<n;++i){
            if(heights[i]>heights[i-1]){
                tot+=(heights[i]-heights[i-1]);
                P.push(heights[i]-heights[i-1]);
            }
    
            if(tot>bricks){
               if(ladders == 0)break;
                tot -= P.top();
                P.pop();
                ladders--;
            }
        }
        ans = i-1;
        return ans;
    }
};
