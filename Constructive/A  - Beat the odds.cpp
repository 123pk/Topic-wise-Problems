/*
Platform :- Codeforces
Approach :- Min count of odd and even values in array 
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
         int c = 0;
         for(int i=0;i<n;++i){
             cin>>A[i];
             if(A[i]%2)c++;
         }
         int ans = min(c,n-c);
         cout<<ans<<"\n";
    }
}
