/*
Platform :- Codeforces
Contest :- Codeforces Round 774 Div 2
Approach :- So we calculate the prefix sum for the given array , and we sort the array and basic idea is to color largest values with red ,let the count of those be 'c' then check
            if we have prefix sum of values of 'c+1' smallest element is lesss than the sum of largest 'c' values then answer exist else no.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         long long A[n];
         long long tot = 0;
         for(int i=0;i<n;++i){
             cin>>A[i];
             tot+=A[i];
         }
         
         sort(A,A+n);
         
         long long pref[n];
         pref[0] = A[0];
         for(int i=1;i<n;++i){
             pref[i] = pref[i-1]+A[i];
         }
         
         int f = 0;
         int d = 0;
         long long sum = 0;
         for(int i=n-1;i>=0;--i){
             sum+=A[i];
             d++;
             if((d+d)<n){
                 if(sum>pref[d]){
                     f=1;break;
                 }
             }
         }
         
         if(f)cout<<"YES\n";
         else cout<<"NO\n";
    }
}
