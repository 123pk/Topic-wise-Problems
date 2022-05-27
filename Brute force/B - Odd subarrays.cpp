/*
Platform :- Codeforces
Contest :- Codeforces Round 794 Div 2
Approach :- We will count no of odd subarrays from left to right and right to left , the max out of both is our solution.
*/
#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&A,int n){
    int count = 0;
    int mn = -1,mx = -1;
    for(int i=0;i<n;++i){
        if(mx == -1){
            mx = A[i];
        }
        else{
            if(mx>A[i]){
                count++;
                mx = -1;
            }
            else mx = max(mx,A[i]);
        }
       // cout<<mx<<" "<<count<<" \n";
    }
    
    return count;
}

int find2(vector<int>&A,int n){
    int count = 0;
    
    int mn = -1;
    for(int i=n-1;i>=0;--i){
        if(mn == -1){
            mn = A[i];
        }
        else{
            if(mn<A[i]){
                count++;
                mn = -1;
            }
            else mn = min(mn,A[i]);
        }
    }
    
    return count;
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
         
         int ans = 0;
         
         //basic stategy is to find the no of subarray from right to left 
         //and left to right and max of them is our aswer
         ans = max(ans,find(A,n));
         ans = max(ans,find2(A,n));
         
         
         cout<<ans<<"\n";
    }
}
