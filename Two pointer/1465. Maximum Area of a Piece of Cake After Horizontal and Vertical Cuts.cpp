/*
Platform :- Leetcode
Approach :- We find the max difference between two lines horizontally and vertically , we consider bounday as lines too , then the product of max difference gives us 
            maximum area of rectangle
*/
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int ans = 0;
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int mx_h = 0;
        int n = horizontalCuts.size();
        
        for(int i=0;i<n;++i){
            if(i == 0){
                mx_h = max(mx_h,horizontalCuts[i]);
            }
             if(i == n-1){
                mx_h = max(mx_h,h-horizontalCuts[i]);
                if(i)mx_h = max(mx_h,horizontalCuts[i]-horizontalCuts[i-1]);
            }
            if(i){
                 mx_h = max(mx_h,horizontalCuts[i]-horizontalCuts[i-1]);
            }
        }
        
        
        int mx_v = 0;
        int m = verticalCuts.size();
        for(int i=0;i<m;++i){
            if(i == 0){
                mx_v = max(mx_v,verticalCuts[i]);
            }
             if(i == m-1){
                mx_v = max(mx_v,w-verticalCuts[i]);
                if(i)mx_v = max(mx_v,verticalCuts[i]-verticalCuts[i-1]);
            }
            if(i){
                 mx_v = max(mx_v,verticalCuts[i]-verticalCuts[i-1]);
            }
        }
        long long x = mx_h;
        long long y = mx_v;
        long long mod = 1e9+7;
        x*=y;
        x%=mod;
        ans= x;
        return ans;
    }
};
