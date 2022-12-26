/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 325
Approach:- We will binary serach on values between 1 and max value,we will also sort the array in increasing order as the ordering doesnot matter.
           Now we will start from first element and will find the count of longest increasing subsequence whose difference between adjacent elements is atleast 'mid'
           if we get atleast 'k' values then 'mid' can be our tastiness ,similarly we will increasea the values and check for bigger values if it satisfies else for
           smaller values.
           
Time Complexity :- O(N log N)
*/
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        //binary search
        int ans = 0;
        sort(price.begin(),price.end());
        int n = price.size();
        int start = 1,end = (price[n-1]),mid =(start+(end-start)/2);
        
        while(start<=end){
            
            //we check if we can have 
            int last = price[0];
            int c = 1;
            for(int i=1;i<n;++i){
                if(price[i]-last >= mid){
                    c++;
                    last = price[i];
                }
            }
            //cout<<c<<" "<<mid<<" "<<start<<" "<<end<<"\n";
            if(c>=k){
                ans = max(ans,mid);
                start = mid+1;
                mid = (start+(end-start)/2);
            }
            else{
                //move down the limit
                end = mid-1;
                mid = (start+(end-start)/2);
            }
        }
        
        
        return ans;
    }
};
