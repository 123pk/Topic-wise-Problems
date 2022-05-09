/*
Platform :- Codeforces
Contest :- Codeforces Round 789 Div2 
Approach :- make an array of integers which store the size of contiguous substring size of same characters ,now traverse from left to right and the difference between odd 
            size index is added to answer , we dont use the used size.
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
         
         vector<int>odd_idx;
         int idx = 0;
         int c = 0;
         char ch = s[0];
         for(int i=0;i<n;++i){
             if(s[i] == ch){
                 c++;
                 if(i == n-1){
                     if(c%2)odd_idx.push_back(idx);
                 }
             }
             else{
                 if(c%2)odd_idx.push_back(idx);
                 idx++;
                 c = 1;
                 if(i == n-1){
                     if(c%2)odd_idx.push_back(idx);
                  }
                 ch = s[i];
             }
         }
         
         int ans = 0;
         for(int i=1;i<odd_idx.size();i+=2){
             ans+=odd_idx[i]-odd_idx[i-1];
         }
         
         cout<<ans<<"\n";
    }
}
