/*
Platform :- Leetcode
Approach :- If you will carefully analyse the problem you will find that you can perform the (ii) operation only once as after that all the values become even and we can only perform 
            first operation , so it is optimal to conver all the values even by multiplying by 2 and we will also maintain min_value of array in variable, we will store all the vlaue
            in max heap and we will reduce the max value of array (val = val/2) till it is divisible by 2 and keep on finding the min value of differene and also update the min_value
            in process.
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        //great intution 
        //If you can observe you will find that you can perfom the second operation
        //only once as the odd become even so only first operation can be perfomed
        //now we will take the max of all even and divide it by 2 till the time it is 
        //even and min of that is our solutio
        for(auto &x:nums){
            if(x%2)x*=2;
        }
        
        priority_queue<int>P;
        int mn = INT_MAX;
        for(auto &x:nums){
            P.push(x);
            mn = min(mn,x);
        }
        
        
        int ans = INT_MAX;
        while(P.top()%2==0){
            ans = min(ans,P.top()-mn);
            mn = min(mn,P.top()/2);
            P.push(P.top()/2);
            P.pop();
        }
        
        return ans = min(ans,P.top()-mn);
    }
};
