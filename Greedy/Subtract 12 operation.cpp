/*
Platform :- Codechef
Contest :- Codechef Lunctime August
Approach :- We will greediy traverse in reverse order (n-1 to 1) , and if ( A[ i ] <= 0) we skip this else we reduce (A[i]/2)*2 value from it and A[i]/2 from A[i-1]
            after modifying the array 
            we again traverse back and change 1,1 adjacent pairs to 0,-1
            
Time Complexity :- O(N)
*/
#include<bits/stdc++.h>
using namespace std;

 

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        vector<long long> A(n);
       // map<long long,int>P;
       // int mx = 0;
       long long tot = 0;
        for(int i=0;i<n;++i){
            cin>>A[i];
           // P[A[i]]++;
           tot+=abs(A[i]);
           // mx = max(mx,P[A[i]]);
        }
        
        
        //it is irrelevant to decrease any -ve value
        //we will not push any vaue to -vity
        //Can we use priority queue
        for(int i=n-1;i>0;--i){
            if(A[i]<=0)continue;
            
            long long z = A[i]/2ll;
            A[i]-=(z*2ll);
            A[i-1]-=z;
        }
        
        //now remove the available ones
        for(int i=n-1;i>0;--i){
            if(A[i]<=0)continue;
            if(A[i]>0 && A[i-1]>0){
                A[i]-=2;
                A[i-1]--;
            }
        }
        
        tot = 0;
        for(auto&x:A)tot+=abs(x);
        cout<<tot<<"\n";
    }
}
