/*
Platform :- Codeforces
Contest :- Codeforces Polynomial Round 2022 (Div. 1 + Div. 2)
Approach :- The main idea is to have a block of size 'k' and we can have 'k' disitinct values only if all values are atleast (max_value-1).
            If (k>m) we cannot have our solution
            Else we will sort the values and choose the smallest (m-(k+1)) values to make the set of values from ((m-k) to m) equal to (max_value-1)
Time Complexity :- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        
        long long A[m];
        for(int i=0;i<m;++i)cin>>A[i];
        
        sort(A,A+m);
        //we need to understand this 
        
        if(k>m)cout<<"NO\n";
        else{
            
            int f = 0;
            long long rem = 0;
            long long sum = 0;
            for(int i=0;i<(m-k);++i){
                sum += A[i];
            }
            
            //I want to convert it to A[m-1]-1
            long long lim = A[m-1]-1;
            
            for(int i=m-k;i<m;++i){
                if(A[i]>=lim)continue;
                long long req = lim - A[i];
                if(sum<req){
                    f=1;
                    break;
                }
                A[i] = lim;
                sum -= req;
            }
            //cout<<"*";
            if(f)cout<<"NO\n";
            else {
                 
                cout<<"YES\n";
                
            }
        }
        
    }
}
