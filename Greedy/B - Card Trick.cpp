/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 129
Approach :- IF size of array is 'n' , then if we do n rotaition we will get back to same array , so find the sum of elements of array B, let it be sum_B,
            sum_B % = n ,  the value at the (sum_B) in array is our answer
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         
         int A[n];
         for(int i=0;i<n;++i)cin>>A[i];
         
         int m;
         cin>>m;
         
         int B[m];
         long long tot = 0;
         for(int i=0;i<m;++i){
             cin>>B[i];
             tot+=B[i];
         }
         
         tot%=n;
         cout<<A[tot]<<"\n";
         
          
     }
}
