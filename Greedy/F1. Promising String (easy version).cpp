/*
Platform :- Codeforces
Contest :- Codeforces Round 780 Div 3
Approach :- We will maintain a prefix array which will store no of increments we can do till ith index ,( change '--' to '+') .
            Now we will traverse through all the subarrays possible of length from 2 to n and will check if the no of ('+') == no of('-') then we will increment our answer
            as they are already good , else we will check if we have enough option to change '--' to '+' such that they are equal.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         string s;
         cin>>s;
         
         /*
         The approach is to check for every substring of legth>2 that we can make equal no of
         + and - sign , we will have to precompute the no of + and - till ith index , then we will also store the no of 
         -- adjacent pairs for each index
         -- for odd length substring we will check if we can modify to change 
         
         Suppose we have a substring of length 5, then we will first check if (no_of_-) - (no_of_+) %3 and == 0 , if we have 
         no of -- adjacent disjoint pairs equal to dif/2 , then we can else we cannot
         
         */
         
         int ans = 0;
         int c = 0,d = 0;
         vector<int>pref(n),suff(n);
         vector<int>neg(n),pos(n);
         int ng = 0,p = 0;
         
         for(int i = 0;i<n;++i){
             if(s[i] == '+'){
                 c = 0;
                 p++;
             }
             else{
                 c++;
                 ng++;
                 if(c == 2){
                     d++;
                     c = 0;
                 }
             }
             neg[i] = ng;
             pos[i] = p;
             pref[i] = d;
         }
         
         c = 0,d = 0;
         for(int i = n-1;i>=0;--i){
             if(s[i] == '+'){
                 c=0;
             }
             else{
                 c++;
                 if(c == 2){
                     d++;
                     c = 0;
                 }
             }
             suff[i] = d;
         }
         
          
         
         for(int i = 2;i<=n;++i){
             for(int j = i-1;j<n;++j){
                 //if we have equal
                 int n_val = neg[j];
                 int p_val = pos[j];
                 int can_do = pref[j];
                 if(j >= i){
                     n_val-=neg[j-i];
                     p_val-=pos[j-i];
                     can_do-=pref[j-i];
                 }
                 
                 if(n_val == p_val)ans++;
                 else{
                     int dif = n_val - p_val;
                     if(dif>0 && ((dif%3 == 0) && (can_do >= (dif/3)))){
                     ans++;
                     }
                 }
             }
         }
         
         cout<<ans<<"\n";
    }
}
