/*
Platform :- Leetcode
Contest :- Weekly contest 283
Approach :- You need to carefully analyse the problem, you will find that a group of disjoint subarrays is formed , a subarray is formed by elements whose combined GCD > 1 and
            we ther is once LCM of those values in subarray at the end we want the LCM of all those disjont subarrays , we make a new subarray when we have LCM of current subarray
            and current element have GCD to be 1.
            
            We use stack for this. We push the first element of our array in stack and now onwards we check if the top element of stack have GCD equal to 1 with nums[i] then we push
            nums[i] in stack else we update the top value with the LCM of two and similarly change other elements of stack until the top element and current LCM dont have GCD 1
*/
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>ans;
        stack<int>hold;
        int last;
        long long val,temp,z;
        for(int i=0;i<nums.size();++i){
            if(hold.size()==0){
                hold.push(nums[i]);
            }
            else{
                int temp = hold.top();
                if(__gcd(temp,nums[i])>1){
                    last = nums[i];
                    while(1){
                        temp = hold.top();
                        val = temp;
                        z = last;
                        val*=z;
                        val/=__gcd(temp,last);
                        last = val;
                        hold.pop();
                        //hold.push(val);
                        if(hold.size()){
                            temp = hold.top();
                            if(__gcd(temp,last)>1)continue;
                            else{
                                hold.push(last);
                                break;
                            }
                        }
                        else{
                            hold.push(last);
                            break;
                        }
                        
                    }
                }
                else{
                    hold.push(nums[i]);
                }
            }
        }
        
        while(!hold.empty()){
            ans.push_back(hold.top());
            hold.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
