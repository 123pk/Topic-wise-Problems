/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 300
Approach :- A person can effect (forget - delay) people only , so we can solve this problem using dp , where dp[i] will give me no of effected people on day[i] ,
            we can affect/share news if and only if I got the news (i-delay)days before, so from (i-delay) to j>(i-forget) , dp[i] += dp[j] ,take care of mod'
            at the end no of people effected from nth day to n-target day sum is our answr
*/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1);
        int  mod = 1e9+7;
        
        for(int i=1;i<=n;++i){
            if(i== 1)dp[i]= 1;
            else{
                if(i<=delay)continue;
                for(int j=i-(delay);j>max(-1,(i-forget));--j){
                    dp[i] = (dp[i] + dp[j])%mod;
                }
            }
        }
     //  for(int i=1;i<=n;++i)cout<<dp[i]<<" ";
      //  cout<<"\n";
        
        int ans = 0;
        for(int i=n;i>(n-forget);--i){
            ans = (ans+dp[i])%mod;
        }
        
        return ans;
    }
};
