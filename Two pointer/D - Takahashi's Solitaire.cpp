/*
Platform :- Atcoder
Contest :- Atcoder Begineer Contest 277
Approach :- We will find the max subarray sum which with consecutive or equal values when sorted in incresing order, keep in mind after last element we move to the first in 
            some case.
            -- Total left over is total sum - max_subarray_sum
Time Complexity :- O(n)
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   long long m;
   cin>>n>>m;
   
   long long tot = 0;
   long long A[2*n];
    
   for(int i=0;i<n;++i){
       cin>>A[i];
       tot += A[i];
   }
   
    int f = 0;
   sort(A,A+n);
   long long val = A[0];
   long long start = A[0];
   long long sum = start;
   for(int i=1;i<n;++i){
       if(A[i] == start){
           sum += start;
       }
       else if(A[i] == (start+1)){
           start++;
           sum +=A[i];
       }
       else{
           f = 1;
            
           sum = A[i];
           start = A[i];
       }
      val = max(val,sum);
   }
   
   start = start+1;
   start%=m;
   for(int i=0;i<n && f;++i){
       if(A[i] == start){
           sum +=start;
           val = max(val,sum);
       }
       else if(A[i] == (start+1)){
           sum += A[i];
           start = A[i];
           val = max(val,sum);
       }
       else{
           break;
       }
   }
   
   tot -= val;
   cout<<tot;
  
}
