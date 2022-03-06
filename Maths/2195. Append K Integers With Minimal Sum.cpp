/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 283
Approach :- 1. Sort the array in non decreasing order ,
            2. The max no of unique values between two no is going to be (max - min)-1 ,
            3. The sum of unique values between two is (sum_of_unique_value_till_max - sum_of_unique_values_till_min )
            4. The forumulae for finding sum of 'n' consecutive numbers is (n*(n+1))/2
            5. We use the above formulae and find the max no of values that we can get and cost of adding them.
*/
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        long long last = 0;
        sort(nums.begin(),nums.end());
        long long val = 0,suml = 0,sumr = 0,l = 0,r = 0;
        
        for(int i=0;i<nums.size();++i){
            val = (nums[i]-last)-1;
            
            if(val<=0){
                last = nums[i];
                continue;
            }
            
            if(val>k){
                //sum till min value
                suml = (last*(last+1))/2;
                //sum till max values that is till (last+k)
                r =last+k;
                sumr = (r*(r+1))/2;
                ans+=(sumr-suml);
                k=0;
                break;
            }else{
                k-=val;
                //sum till min value
                suml = (last*(last+1))/2;
                
                r = last+val;
                //sum till max values that is till r
                sumr = (r*(r+1))/2;
                ans+=(sumr-suml);
                
                if(k==0)break;
            }
            last = nums[i];
        }
       // cout<<k<<" "<<ans<<" "<<last<<"\n";
        if(k){
            suml = (last*(last+1))/2;
            r = (last+k);
            sumr = (r*(r+1))/2;
            ans+=(sumr-suml);
        }
        
        return ans;
    }
};
