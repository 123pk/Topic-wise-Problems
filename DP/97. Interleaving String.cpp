/*
Platform :- Leetcode
Approach :- So we will first write one recursive solution , where we maintain three pointers pointer to start of each string (s1,s2 ans s3) respectively in the beginning
           , we will check ------> if(s1[i] == s3[k]) then we check for (i+1,j,k+1) 
              ---->   if(s2[j] == s3[k] ) then we check for (i,j+1,k+1) ,
              in this way we get all the possible combination . If 'i' or 'j'  are equall to string s1.size() or s2.size() then we check with respective value'j' or 'i' and'k'
              in order to avoid calculating for overlapping subtasks we will use memoisation.
*/
class Solution {
public:
    //we will  use memoisation for not calcualting already calculated subtask(overlapping ones)
    int dp[101][101];
    
    bool find(int i,int j,int k,string& s1,string& s2 , string& s3){
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(i == s1.size()){
            if(s2[j] != s3[k]){
                return dp[i][j] = 0;
            }
            else{
                if((j+1)<s2.size())dp[i][j] = find(i,j+1,k+1,s1,s2,s3);
                else dp[i][j] = 1;
                return dp[i][j];
            }
        }
        else{
            if(j == s2.size()){
                if(s1[i] != s3[k])return dp[i][j]= 0;
                else{
                    if((i+1) < s1.size()) dp[i][j] = find(i+1,j,k+1,s1,s2,s3);
                    else dp[i][j] = 1;
                    return dp[i][j];
                }
            }
            else{
                
                //check both the options
                int val  = 0,val2 = 0;
                //we have matching character in s1 and s3 then we check for (i+1,j,k+1)
                if(s1[i] == s3[k])val = find(i+1,j,k+1,s1,s2,s3);
                
                //we have matching character in s2 and s3 then we check for (i,j+1,k+1)
                if(s2[j] == s3[k])val2 = find(i,j+1,k+1,s1,s2,s3);
                val= val or val2;                             
                return dp[i][j] = val;
            }
        }
        
        
         
    }
        
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size()) != s3.size())return false;
         memset(dp,-1,sizeof(dp));
        
        int val = find(0,0,0,s1,s2,s3);
       
        return val==1;
    }
};
