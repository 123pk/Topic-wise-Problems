/*
Platform :- Codechef
Contest :- Codechef Starters 35 Div 2 April 2022
Appraoch :- We need to find no of pairs A[i] , A[j] such that ( (A[i] xor A[j]) and X  = 0  ) , you need to know the following property of XOR and AND 
            the following expression can be written as ( (A[i] and X) xor (A[j] and X) = 0 ) , from this we can know that we will first covert each value into 
            A[i] and X , now for XOR to be equal to '0' we will have to have same value element so ,let 'y' = count of A[i] so no valid pairs   = y*y
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
       // long long x;
        //vector<int>count(32);
        for(int i=0;i<n;++i){
            cin>>A[i];
            
        }
        long long x;
        cin>>x;
        map<long long,long long>count;
        long long ans = 0;
        for(int i=0;i<n;++i){
            A[i] = A[i] & x;
            count[A[i]]++;
        }
        
        for(auto&x:count){
            long long val = x.second;
            val*=val;
            ans+=val;
        }
        
        cout<<ans<<"\n";
    }
}
