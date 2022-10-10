/*
Platform :- Codeforces
Contest :- Codeforces Round 825 Div 2
Approach :- So for a given subarray if current element can be added if A[i] >= c+1 , where 'c' is current size of subarray ,
            else we will move the start pointer of subarray until A[i] >= c , and each element contribute 'c' points to answer.
            
Time Complextiy :- O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int A[n];
        for(int i=0;i<n;++i)cin>>A[i];
        
        long long ans = 0,c = 1;
        for(int i=0;i<n;++i){
            if(A[i] >= c){
                ans += c;
                c++;
            }
            else{
                
                 while(c>A[i])c--;
                 ans += c;
                 c++;
            }
           // cout<<ans<<' ';
        }
        cout<<ans<<"\n";
    }
}
