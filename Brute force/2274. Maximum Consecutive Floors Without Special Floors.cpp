/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 293
Approach :- Add the bottom and top value in array and sort in increasing order now find the max difference betweeen adjacent elements and that is our required answer 
*/
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        
        special.push_back(bottom);
        special.push_back(top);
        sort(special.begin(),special.end());
        
        for(int i=1;i<special.size();++i){
            int val = special[i]-special[i-1];
            if(i>1 && i<special.size()-1)val--;
            ans = max(ans,val);
        }
        return ans;
    }
};
