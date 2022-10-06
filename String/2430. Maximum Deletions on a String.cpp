/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 313
Approach :- I have use KMP + dp for the solution ,
            1. I have precalculated the 'vector' of indices which follow the condition ( first i letters of s are equal to the following i letters in s)
               for each substring from ( j to n-1) for all 'j' from [0,n-1] , I have vector of those indices 
               so if I am at 'j' I can jump to ('j'+ idx[i]) as they will satisfy the condition.
               
               I have used KMP for comparing the string and finding those indices.
            2. Now for all the indices I have found the max value I can get if I start from there .
Time Comlexity :- O(n*n)
*/ 
//this functions finds the ith value for string usng KMP algorithms 
// first 'i' letters and following 'i' letters of string are equal
//this functions finds the ith value for string usng KMP algorithms 
// first 'i' letters and following 'i' letters of string are equal

vector<int> indexes(string&s){
    
    int n = s.size();
    vector<int>len(n);
    vector<int>ans;
    len[0] = 0;
    int j = 0;
    
    for(int i=1;i<n;++i){
        if(s[i] == s[j]){
            j++;
        }
        else{
            j = 0 ;
        }
        len[i] = j;
    }
  
    for(int i=n-1;i>=0;--i){
        int cur = i+1;
        int val = len[i]*2;
        //here we are getting the actual index 'i'
        if(cur == val){
            ans.push_back(len[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    //we don't want empty answer so we will add '0'
    if(ans.size() == 0)ans.push_back(0);
    return ans;
}


class Solution {
public:
    
    int dp[4001];
    vector<int>cur;
    
    //we will use dp to memoise the recursive solution
    //idea is to move for each of the index from current index that is satisfying 
    //the given condition 
    
    int find(int i,string& s,vector<vector<int>>&pre){
        if(i>=s.size())return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int val = 0;
        
        cur.clear();
        cur = pre[i];
        if(cur.size() == 1 && cur[0] == 0){
            return dp[i] = 1;
        }
        
        //getting all the indexes which have first 'j' letters and following 'j' letters of string are equal 
        //from index 'i'
        for(auto&x:cur){
            val = max(val,find(i+x,s,pre)+1);
        }
        
        return dp[i] = val;
    }
    
    int deleteString(string s) {
        
        
        int n = s.size();
        vector<vector<int>>pre(n);
        string temp = "";
        string z = "";
        
        //storing the repeating indexes for each index.
        for(int i=n-1;i>=0;--i){
            temp += s[i];
            z = "";
            z = temp;
            reverse(z.begin(),z.end());
            pre[i] = (indexes(z));
        }
       
        memset(dp,-1,sizeof(dp));
        
        return find(0,s,pre);
    }
};
