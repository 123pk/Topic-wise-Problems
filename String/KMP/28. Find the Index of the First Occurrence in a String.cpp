/*
Platform :- Leetcode
Approach :- We will use KMP algorithms for efficiently comparing the strings .
Time Complexity :- O(n+m)
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        //this problem is good for using kmp
        
        int m = needle.size();
        int n = haystack.size();
        if(m>n)return -1;
        
        vector<int>pre_process(m);
        int j = 0;
        for(int i=1;j<m && i<m;){
            if(needle[i] == needle[j]){
                j++;
               
                pre_process[i] = j;  i++;
            }
            else{
                if(j){
                   j = pre_process[j-1]; 
                }
                else {
                    pre_process[i] = 0;
                    i++;
                }
            }
        }

        
        
        int ans = -1;
         j = 0;
        //now we compare

        for(int i=0;i<n;){
           if(haystack[i] == needle[j]){
               j++;
               if(j == needle.size()){
                   return ((i+1)-j);
               }++i;
           }    
           else{
              //we need to move a to left
              if(j == 0){
                  i++;continue;
              }
              else j = pre_process[j-1];
           }
        }
        return ans;
    }
};
