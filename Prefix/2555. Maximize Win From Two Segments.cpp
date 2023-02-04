/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 97
Approach :- We can observe that since we can choose two segment , for each index we can find the max_value in segment from [0,i] or left_segment 
            and max_value for right segment [i+1,n-1] 
            Using Sliding window and prefix and suffix array we can find the max count for each index 'i' to its left and to its right.
            The max value of prefix[i] + suff[i+1] , is our answer.
Time Complexity :- O(n)
*/
class Solution {
public:
    int maximizeWin(vector<int>& A, int k) {
        int ans = 0;
        //k+=k;
        int start = 0 ;
        int count = 0;
        int end = A[0] + k;
        int n = A.size();
        int cur_val = 0;
        vector<int>pref(n),suff(n);
        for(int i=0;i<n;++i){
            int cur = A[i];
            
            if(cur<= end){
                count++;
            }
            else{
                while(cur>end){
                    start++;
                    end = A[start]+k;
                    count--;
                }
                count++;
            }
            cur_val = max(cur_val,count);
            pref[i] = cur_val;
        }
        
        start = n-1;
        end = A[n-1] - k;
        count = 0,cur_val = 0;
        for(int i=n-1;i>=0;--i){
            int cur = A[i];
            
            if(cur>=end){
                count++;
            }
            else{
                while(cur<end){
                    start--;
                    end = A[start]-k;
                    count--;
                }
                count++;
                 
            }
            cur_val = max(cur_val,count);
            suff[i] = cur_val;
        }
        
        for(int i=0;i<n;++i){
            int sum = pref[i];
            if((i+1)<n)sum += suff[i+1];
            ans = max(ans,sum);
        }
      
        
        return ans;
    }
};
