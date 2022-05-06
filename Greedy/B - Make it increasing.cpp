/*
Platform :- Codeforces
Contest :- Codeforces Round 787 Div 3
Approach :- We will start from last element and traverse to the first , Since we can only change the value by diving them by 2 , so this means we cannot increase values
            we will start from last and if current element ( A[i] < A[i+1]) then we dont do anythign because it is already in increasing order, else we change it until
            the value of A[i] is smaller and "count" it, if at any point we reach to '0' then we cannot convert the array and print "-1" else print the "count".
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
         for(int i=0;i<n;++i){
             cin>>A[i];
         }
         
         int f = 0,c = 0;
         long long last;
         for(int i = n-1; i>=0 ;--i){
             if(i == n-1)last = A[i];
             else{
                 //this means all the values to right of this are 
                 //strictly greater than current value
                 if(A[i]<last){
                     last = A[i];
                     continue;
                 }
                 else{
                     if(last == 0){
                         f=1;break;
                     }
                     while(1){
                        A[i]/=2ll;
                        c++;
                        if(A[i]<last)break;
                     }
                     last = A[i];
                 }
             }
         }
         
         if(f)cout<<"-1\n";
         else cout<< c<<"\n";
    }
}
