/*
Platform :- Codeforces 
Contest :- Codeforces Round 801 Div 2
Approach :- If n is odd then , Mike will always win .
            If n is even, then there are two cases when the smallest value that one can get in their turn is equal , then the first player to reach to smallest value
            is looser , if the smallest values are different then the one with smaller min value looses.
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
         vector<long long>mike,joe;
         long long mn1 = 1e18,mn2  = 1e18;
         for(int i=0;i<n;++i){
             cin>>A[i];
             if(i%2 == 0){
                 mike.push_back(A[i]);
                 mn1 = min(mn1,A[i]);
             }
             else {
                 joe.push_back(A[i]);
                 mn2 = min(mn2,A[i]);
             }
         }
         
         if(n%2)cout<<"Mike\n";
         else if(mn1>mn2)cout<<"Mike\n";
         else if(mn1<mn2)cout<<"Joe\n";
         else {
             int idx1 = 0;
             int idx2 = 0;
             for(int i=0;i<mike.size();++i){
                 if(mike[i] == mn1){
                     idx1 = i;
                     break;
                 }
             }
             
             for(int i = 0;i<joe.size();++i){
                 if(joe[i] == mn2){
                     idx2 = i;
                     break;
                 }
             }
             
             if(idx1>idx2)cout<<"Mike\n";
             else cout<<"Joe\n";
             
         }
    }
         
}
