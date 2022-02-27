/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 282
Approach :- Since the value of time is in range from 1 to 10^14 atmax , we will do binary search on the values and find the smallest value that satisfy the condition 
*/
class Solution {
public:
    //Why I was not able to understand this is binary search
    
    long long minimumTime(vector<int>& A, int tot) {
        long long ans = 0;
        sort(A.begin(),A.end());
        
        
        long long start = 1,end = 1e15,mid = (start+end)/2,sum = A[0];
        sum*=tot;
        ans = sum;
        
        while(start<=end){
            sum = 0;
            
            for(auto&x:A){
                sum+=(mid/x);
                if(sum>=tot){
                    break;
                }
            }
            if(sum>=tot){
                end = mid-1;
                ans = min(ans,mid);
                mid = (start+end)/2;
            }
            else{
                start = mid+1;
                mid = (start+end)/2;
            }
        }
        return ans;
    }
} ;
