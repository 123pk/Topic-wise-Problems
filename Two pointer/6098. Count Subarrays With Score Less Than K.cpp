/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 80
Approach :- We try to find the longest subarray which satisfy the condition while traversing from left to riht (0 to n-1) using two pointer , we will push those ranges
            in array and  no of subarrays which satisfies the condition for len 'x'  = 'x'*(x+1)/2 , we will remove overlapping values which are added multiple times 
            we just want to add single times.
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans= 0;
        
        //so idea is to find the longest subarray as we move from left to right 
        //and if length of it is 'x' then no of subarray satisfying it is x*(x+1)/2
        
        vector<pair<int,int>>temp;
        long long tot = 0,d = 0,val;
        int start = 0,end = 0;
        for(int i=0;i<nums.size();++i){
            tot+=nums[i];
            d++;
            end = i;
            val = (tot*d);
            if(val<k){
                if(i == nums.size()-1)temp.push_back({start,end});
            }
            else{
                if(start < end)temp.push_back({start,end-1});
                while(start<=end){
                    val = tot*d;
                    if(val>=k){
                        d--;
                        tot-=nums[start];
                        start++;
                    }
                    else break;
                }
                
                if(i == nums.size()-1){
                    if(start<=end)temp.push_back({start,end});
                }
            }
        }
        
        int lstart = -1,lend = -1;
        //now in pairs remove the overlapping ones
        for(int i=0;i<temp.size();++i){
            //this is the total no of subarray we can get from the range
            long long dif = (temp[i].second - temp[i].first) + 1ll;
            ans+=(dif*(dif+1))/2ll;
              
            //now remove the overlapping
            if(temp[i].first<=lend){
                long long com = (lend - temp[i].first)+1ll;
                ans-=(com*(com+1ll))/2ll;
            }
            lstart = temp[i].first;
            lend = temp[i].second;
            //cout<<ans<<" \n";
        }//cout<<ans<<" \n";
        
        return ans;
    }
};
