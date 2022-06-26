/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 299
Approach :- We maintain two change arrays , they store what is the benefit or change in sum we are going to get if we replace A[i] with B[i] , now in both arrays we
             find maximum sum subarray and then answer is max(tot1 + max_subarray_sum1 + tot2 + max_subarray_sum2)
*/
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<int>change1(n),change2(n);
        
        int tot1 = 0,tot2 = 0;
        for(int i=0;i<n;++i){
            change1[i] = nums2[i] - nums1[i];
            change2[i] = nums1[i] - nums2[i];
            
            tot2 += nums2[i];
            tot1 += nums1[i];
        }
        
        int sum1 = 0,mx1 = 0;
        for(int i=0;i<n;++i){
            //I will find the max sum subarray from it
            sum1 += change1[i];
            mx1 = max(mx1,sum1);
            if(sum1<0){
                sum1 = 0;
            }
        }
        
        //similary for change 2
         int sum2 = 0,mx2 = 0;
        for(int i=0;i<n;++i){
            //I will find the max sum subarray from it
            sum2+= change2[i];
            mx2 = max(mx2,sum2);
            if(sum2<0){
                sum2 = 0;
            }
        }
        
        int ans = max(mx1 + tot1, mx2 + tot2);
        return ans;
    }
};
