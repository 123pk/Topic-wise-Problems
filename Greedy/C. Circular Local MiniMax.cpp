/*
Platform :- Codeforces
Contest :- Codeforces Round 794 Div 2
Approach :- First we will sort our first array and after that we will check if our second array is sorted or not , if it is not sorted and the elements which we need to
            swap are distinct in array 1 we cannot sort it as if we will try to swap them then it will make array 1 unsorted .
            else we print the indexes we need to swap .
Runtime :- O(n log n) --> due to sorting
*/
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>&B){
    for(int i=0;i<B.size();i+=2){
        if(i == 0){
            if(B[i]>B[i+1] && B[i]>B[B.size()-1]){
                
            }
            else return false;
        }
        else{
            if(B[i]>B[i-1] && B[i]>B[i+1]){
                
            }
            else return false;
        }
    }
    return true;
}
 
int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         
         vector<int> A(n);
         for(int i=0;i<n;++i){
             cin>>A[i];
         }
         
         if(n%2)cout<<"NO\n";
         else{
             //chek karna padega
             sort(A.begin(),A.end());
             int idx = n/2;
             idx--;
             vector<int>B(n);
             int last = n-1;
             for(int i = 0;i<n;i+=2){
                 B[i] = A[last];
                 B[i+1] = A[idx];
                 last--;
                 idx--;
             }
             
             if(check(B)){
                 cout<<"YES\n";
                 for(auto&x:B)cout<<x<<" ";
                 cout<<"\n";
             }
             else cout<<"NO\n";
         }
    }
}
