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
