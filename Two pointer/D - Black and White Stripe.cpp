/*
Platform :- Codeforces
Contest :- Codeforces Round 797 Div 3
Approach :- We will look for no of black cell in window of size 'k' using sliding window, the min no of white no of cells in any window is our answer.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int n,k;
         cin>>n>>k;
          
          
         string s;
         cin>>s;
         
         int black = 0;
         int ans = 0;
         //now find the values
         for(int i=0;i<k;++i){
             if(s[i] == 'B')black++;
         }
         ans = (k-black);
         for(int i=k;i<n;++i){
             if(s[i-k] == 'B')black--;
             if(s[i] == 'B')black++;
             ans = min(ans,k - black);
         }
         
         cout<<ans<<"\n";
    }
}
