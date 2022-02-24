/*
Platform :- Codechef
Contest :- Codechef Starters 27 
Approach :- Greedily choose index just before and after some value and change it to their value*2.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         int A[n];
         for(int i=0;i<n;++i)cin>>A[i];
         
         int d = 0;
         
         
         //cout<<d<<" --> ";
         
         for(int i=1;i<n;i+=3){
             A[i] = A[i-1]*2;
             d++; 
         }
         
         for(int i=2;i<n;i+=3){
             if((i+1)<n){
                 A[i] = A[i+1]*2;
             }else A[i] = 2;
             d++;
         }
         
         
         int lim = n*2;
         int c = lim/3;
         if(lim%3)c++;
         
         //cout<<c<<" "<<d<<"\n";

         for(auto&x:A)cout<<x<<" ";
         cout<<"\n";
    }
}

 
