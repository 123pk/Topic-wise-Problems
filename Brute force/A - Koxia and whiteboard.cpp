/*
Platform :- Codeforces
Contest :- Codeforces Bye 2022
Approach:- We will perform the operation m times and each time we will update the smallest value as it will have the max difference that we can have .
           at the end find the sum
Time Complexity :- O(n log n*m)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        long long A[n];
        long long tot = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
            tot += A[i];
        }
        
        long long B[m];
        for(int i=0;i<m;++i){
            cin>>B[i];
        }
        
        sort(A,A+n);
        int j = 0;
        while(j<m){
            sort(A,A+n);
            
            tot += B[j]-A[0];
            A[0] = B[j];
            j++;
        }
        
        cout<<tot<<"\n";
    }
}
