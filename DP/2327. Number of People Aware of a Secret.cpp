/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 300
Approach :- A person can effect (forget - delay) people only , so we can solve this problem using dp , where dp[i] will give me no of effected people on day[i] ,
            we can affect/share news if and only if I got the news (i-delay)days before, so from (i-delay) to j>(i-forget) , dp[i] += dp[j] ,take care of mod'
            at the end no of people effected from nth day to n-target day sum is our answr
*/
