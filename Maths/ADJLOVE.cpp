/*
Platform :- Codechef
Contest :- Codechef Lunctime march 2022
Approach :- if we have odd no of consecutive odd numbers then the sum of product is even , so we want to have even odd no cosecutively , if we have only one odd no then 
            it is not possible , or if we have '0' odd number or all odd number then also we have no possible permutation.
            else we take all the even values in beginning and odd at the end , if we have odd no of odd numbers then we add one odd number to beginning ,before even numbers
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         int c = 0;
         long long A[n];
         for(int i=0;i<n;++i){
             cin>>A[i];
             if(A[i]%2ll)c++;
             
         }
         
         int d = n-c;
         
         if(c == 1)cout<<"-1\n";
         else if((c%2 && c==n) || c==0)cout<<"-1\n";
         else{
             vector<long long>odd,even;
             for(auto&x:A){
                 if(x%2)odd.push_back(x);
                 else even.push_back(x);
             }
             
             //we choose the even indexes first and odd at the end
             if(c%2){
                 cout<<odd[0]<<" ";
                 for(auto&x:even)cout<<x<<" ";
                 for(int i=1;i<odd.size();++i)cout<<odd[i]<<" ";
                 cout<<"\n";
             }
             else{
                 for(auto&x:odd)cout<<x<<" ";
                 for(auto&x:even)cout<<x<<" ";
                 cout<<"\n";
             }
         }
         
         
    }
}
