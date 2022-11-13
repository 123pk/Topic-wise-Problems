/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 318
Approach :- We will first find the palindromes of size 'k' and 'k+1' , the reason being we don't care about all other values greater than >= (k+1) because 
            if we have a palindrome of size (k+2) then we will have a plindrome of size (k) also and same for (k+3) and beyonds.
            So now we maintain a set where we store the 'starting' and 'ending' index of the palindrome of size (k) and (k+1)
           -- No we use ('recursion' + 'memoisation') , where for 'i'th index we have few options,
            -- we check if there is any palindrome startin from this index of size (k) or (k+1) , if we have then we increse our count and get the max value for
               ((i-(k)),0) and ((i-(k+1)),0).
            -- else we find the total number of palindromes from (i-1 to 0)
Time Complexity :- O(n^2 log n)
*/


class Solution {
public:
    
    int dp[2000][2000];
    
    int find(int i,int cnt,string&s ,int k,set<pair<int,int>>&P){
        
        if(dp[i][cnt] != -1)return dp[i][cnt];
        
        //else I hvae opition
        if(i == 0){
            return dp[i][cnt] = 0;
        }
        else{
            int val = 0;
            //we will look for palindrome
            if(((i+1)-k)>=0){
                if(P.find({(i+1)-k,i}) != P.end()){
                    //there is palindrome
                    val = 1 ;
                    if((i-k)>=0)val += find(i-k,cnt+1,s,k,P);
                }
            }
            
              //get a bigger value too
                if((i-k)>=0){
                    if(P.find({i-k,i}) != P.end()){
                       //there is palindrome
                       int z = 1 ;
                       if(i-(k+1)>=0)z += find(i-(k+1),cnt+1,s,k,P);
                        val = max(val,z);
                    }
                }
            
            val = max(val,find(i-1,cnt+1,s,k,P));
            
            
            
            return dp[i][cnt] = val;
        }
    }
    
    int maxPalindromes(string s, int k) {
        if(k == 1)return int(s.size());
        //check if it is palindrome
        set<pair<int,int>>P;
        int n = s.size();
        for(int i=0;i<=(n-k);++i){
            //for string from i to i+k
            int end = (i+k);
            int f = 0;
            for(int j=0;j<(k/2);++j){
                if(s[i+j] != s[end-1-j]){
                    f=1;
                    break;
                }
            }
            if(f == 0)P.insert({i,end-1});
        }
        
        
            //I get a bigger size also
            int sz = k;
            k++;
            for(int i=0;i<=(n-k);++i){
               //for string from i to i+k
              int end = (i+k);
              int f = 0;
              for(int j=0;j<(k/2);++j){
                  if(s[i+j] != s[end-1-j]){
                      f=1;
                      break;
                   }
               }
               if(f == 0)P.insert({i,end-1});
            }
            k = sz;
        
        
        if(P.size() == 0)return 0;
        
        ///for(auto&x:P)cout<<x.first<<" "<<x.second<<"\n";
        
        memset(dp,-1,sizeof(dp));
        return find(n-1,0,s,k,P);
    }
};
