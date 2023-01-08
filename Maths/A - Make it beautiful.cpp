/*
Platform :- Codeforces
Contest :- Educational round 141
Appraoch :- Sort the values in increasing order ,now reverse them and swap second and last element if possible .
           In this way we are not going to have any array whose sum of prefix [i-1] = A[i] until all values are same
Time Complexity :- O(n log n)
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
        
        sort(A,A+n);
        reverse(A,A+n);
        if(n>1)swap(A[1],A[n-1]);
        
        long long tot = 0;
        int f = 0;
        for(int i=0;i<n;++i){
            if(tot == A[i]){
                f=1;
                break;
            }
            tot += A[i];
        }
        
        if(f)cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(auto&x:A)cout<<x<<" ";
            cout<<"\n";
        }
    }
}
