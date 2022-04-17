/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 289 
Approach :- Since we can choose '2' or '3' values of same type at a time so if we have an element with just '1' frequency then it is not possible
            else for all other cases no of operation required per element is value = (x/3) , if(x%3)value++ , here 'x' = frequecy of element
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        map<int,int>count;
        for(auto&x:tasks){
            count[x]++;
        }
        
        for(auto&x:count){
            if(x.second == 1)return -1;
            int val = x.second/3;
            int rem = x.second%3;
            if(rem){
                ans+=(val+1);
            }
            else ans+=(val);
        }
        
        return ans;
    }
};
