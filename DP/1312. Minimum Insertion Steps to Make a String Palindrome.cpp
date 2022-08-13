/*
Platform :- Leetcode
Approach :- We will maintain two pointers one will point to the end and one to the front , if the chanracteres are equal then we (i++) and (j--) ,
            if they are not equal then we have two option 
             --- either to add one character similar to (ith) character in end 
             --- or add character similar to (jth) character in front 
             we will check for both operation and consider the one with minimum cost ,we will use memoisation to make our code more efficient.
*/
class Solution {
public:
    int dp[501][501];
    
    int find(int i,int j,string& s){
        if(i >= j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
        //here we have i < j
        //so we have two option either to add one element to make i equal or add one 
        //to make jth character of s equal
        //what is current values are eual we move to next
        if(s[i] == s[j]){
            return dp[i][j] = find(i+1,j-1,s);
        }
        else{
            int val = min(1 + find(i+1,j,s),1+find(i,j-1,s));
            return dp[i][j] = val;
        }
        
    }
    
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return find(0,n-1,s);
    }
};
